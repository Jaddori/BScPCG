using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;
using System.Xml;

namespace AutoTester
{
    public partial class MainForm : Form
    {
        private bool running;
        private string testFile;
        private string outputFile;
        private DateTime prevTime;
        private int totalTests;
        private int successfulTests;

        public MainForm()
        {
            InitializeComponent();
        }

        private void MainForm_Load(object sender, EventArgs e)
        {
            testFile = string.Empty;
            outputFile = string.Empty;
            prevTime = DateTime.MinValue;
            running = false;
        }

        private void txt_testFile_TextChanged(object sender, EventArgs e)
        {
            testFile = txt_testFile.Text;
        }

        private void txt_outputFile_TextChanged(object sender, EventArgs e)
        {
            outputFile = txt_outputFile.Text;
        }

        private void btn_browseTestFile_Click(object sender, EventArgs e)
        {
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                txt_testFile.Text = openFileDialog.FileName;
            }
        }

        private void btn_browseOutputFile_Click(object sender, EventArgs e)
        {
            if( saveFileDialog.ShowDialog() == DialogResult.OK )
            {
                txt_outputFile.Text = saveFileDialog.FileName;
            }
        }

        private void btn_start_Click(object sender, EventArgs e)
        {
            if (running)
            {
                watchTimer.Stop();
                btn_start.Text = "Start";
                running = false;
            }
            else
            {
                if (testFile == string.Empty)
                    MessageBox.Show("Failed to start.\nNo test file selected.", "AutoTester - Error");
                else if (!File.Exists(testFile))
                    MessageBox.Show("Failed to start.\nTest file is invalid.", "AutoTester - Error");
                else if (outputFile == string.Empty)
                    MessageBox.Show("Failed to start.\nNo output file selected.", "AutoTester - Error");
                else
                {
                    RunTests();

                    watchTimer.Start();
                    btn_start.Text = "Stop";
                    running = true;
                }
            }
        }

        private void watchTimer_Tick(object sender, EventArgs e)
        {
            RunTests();
        }

        private void RunTests()
        {
            try
            {
                DateTime curTime = File.GetLastWriteTime(testFile);
                if (curTime != prevTime)
                {
                    prevTime = curTime;

                    lbl_runtime.Text = curTime.ToString();

                    ProcessStartInfo startInfo = new ProcessStartInfo(testFile, "--gtest_output=xml:" + outputFile);
                    startInfo.CreateNoWindow = true;
                    startInfo.UseShellExecute = false;
                    startInfo.WorkingDirectory = Path.GetDirectoryName(testFile);
                    Process p = Process.Start(startInfo);
                    p.WaitForExit();

                    ReadResults();
                }
            }
            catch (Exception exc)
            {
                lbl_runtime.Text = "FAILED";
            }
        }

        private void ReadResults()
        {
            /*XmlReader xmlReader = XmlReader.Create(outputFile);

            while (xmlReader.Read())
            {
                if (xmlReader.NodeType == XmlNodeType.Element)
                {
                    string name = xmlReader.Name;
                    switch (name)
                    {
                        case "testsuite":
                            string testsuiteName = xmlReader.GetAttribute("name");
                            int testsuiteTests = int.Parse(xmlReader.GetAttribute("tests"));
                            int testsuiteFailures = int.Parse(xmlReader.GetAttribute("failures"));
                            int testsuiteSucceses = testsuiteTests - testsuiteFailures;
                            float testsuiteTime = float.Parse(xmlReader.GetAttribute("time"));

                            TreeNode testsuiteNode = new TreeNode(testsuiteName + " (" + testsuiteSucceses.ToString() + "/" + testsuiteTests.ToString() + ") " + testsuiteTime + "s");

                            ReadTestsuite( xmlReader );
                            break;
                    }
                }
            }

            xmlReader.Close();*/

            tree_results.Nodes.Clear();
            totalTests = 0;
            successfulTests = 0;

            XmlDocument doc = new XmlDocument();
            doc.Load(outputFile);

            foreach (XmlNode node in doc.ChildNodes[1])
            {
                if (node.Name == "testsuite")
                {
                    ReadTestsuite(node);
                }
            }

            string tip = successfulTests.ToString() + "/" + totalTests.ToString() + " tests succeeded.";
            notifyIcon.Text = tip;
            notifyIcon.BalloonTipText = tip;
            notifyIcon.ShowBalloonTip(2000);
        }

        /*private void ReadTestsuite(XmlReader xmlReader)
        {
            while (xmlReader.Read())
            {
                if (xmlReader.NodeType == XmlNodeType.EndElement)
                    break;
                else if( xmlReader.NodeType == XmlNodeType.Element )
                {
                    if (xmlReader.Name == "testcase")
                    {
                        string name = xmlReader.GetAttribute("name");
                        float time = float.Parse(xmlReader.GetAttribute("time"));

                        if( xmlReader.has)
                    }
                }
            }
        }*/

        private void ReadTestsuite(XmlNode parent)
        {
            string name = parent.Attributes["name"].Value;
            int tests = int.Parse(parent.Attributes["tests"].Value);
            int failures = int.Parse(parent.Attributes["failures"].Value);
            int successes = tests - failures;
            float time = float.Parse(parent.Attributes["time"].Value.Replace('.', ','));

            totalTests += tests;
            successfulTests += successes;

            TreeNode testsuiteNode = new TreeNode(name + " (" + successes.ToString() + "/" + tests.ToString() + ") - " + time.ToString() + "s");
            testsuiteNode.BackColor = Color.LightGreen;

            foreach (XmlNode node in parent.ChildNodes)
            {
                if (node.Name == "testcase")
                {
                    //testsuiteNode.Nodes.Add(ReadTestcase(node));
                    if (!ReadTestcase(node, testsuiteNode))
                        testsuiteNode.BackColor = Color.IndianRed;
                }
            }

            tree_results.Nodes.Add(testsuiteNode);
        }

        private bool ReadTestcase(XmlNode parent, TreeNode testsuiteNode)
        {
            string name = parent.Attributes["name"].Value;
            float time = float.Parse(parent.Attributes["time"].Value.Replace('.', ','));

            TreeNode testcaseNode = new TreeNode(name + " - " + time + "s");

            if (parent.ChildNodes.Count > 0)
            {
                testcaseNode.BackColor = Color.IndianRed;

                foreach (XmlNode node in parent.ChildNodes)
                {
                    if (node.Name == "failure")
                    {
                        ReadFailure(node, testcaseNode);
                    }
                }
            }
            else
                testcaseNode.BackColor = Color.LightGreen;

            testsuiteNode.Nodes.Add(testcaseNode);

            return ( parent.ChildNodes.Count <= 0 );
        }

        private void ReadFailure(XmlNode node, TreeNode testcaseNode)
        {
            XmlCDataSection cdata = node.ChildNodes[0] as XmlCDataSection;

            TreeNode messageNode = new TreeNode(cdata.Data);
            testcaseNode.Nodes.Add(messageNode);
        }

        private void MainForm_Resize(object sender, EventArgs e)
        {
            if (WindowState == FormWindowState.Minimized)
            {
                Hide();
            }
        }

        private void notifyIcon_Click(object sender, EventArgs e)
        {
            Show();
            WindowState = FormWindowState.Normal;
        }
    }
}
