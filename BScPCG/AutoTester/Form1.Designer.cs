namespace AutoTester
{
    partial class MainForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MainForm));
            this.tree_results = new System.Windows.Forms.TreeView();
            this.lbl_test = new System.Windows.Forms.Label();
            this.txt_testFile = new System.Windows.Forms.TextBox();
            this.btn_browseTestFile = new System.Windows.Forms.Button();
            this.lbl_outputFile = new System.Windows.Forms.Label();
            this.txt_outputFile = new System.Windows.Forms.TextBox();
            this.btn_browseOutputFile = new System.Windows.Forms.Button();
            this.btn_start = new System.Windows.Forms.Button();
            this.lbl_results = new System.Windows.Forms.Label();
            this.watchTimer = new System.Windows.Forms.Timer(this.components);
            this.openFileDialog = new System.Windows.Forms.OpenFileDialog();
            this.saveFileDialog = new System.Windows.Forms.SaveFileDialog();
            this.lbl_runtime = new System.Windows.Forms.Label();
            this.notifyIcon = new System.Windows.Forms.NotifyIcon(this.components);
            this.SuspendLayout();
            // 
            // tree_results
            // 
            this.tree_results.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tree_results.Location = new System.Drawing.Point(12, 119);
            this.tree_results.Name = "tree_results";
            this.tree_results.Size = new System.Drawing.Size(260, 331);
            this.tree_results.TabIndex = 0;
            // 
            // lbl_test
            // 
            this.lbl_test.AutoSize = true;
            this.lbl_test.Location = new System.Drawing.Point(12, 9);
            this.lbl_test.Name = "lbl_test";
            this.lbl_test.Size = new System.Drawing.Size(47, 13);
            this.lbl_test.TabIndex = 1;
            this.lbl_test.Text = "Test file:";
            // 
            // txt_testFile
            // 
            this.txt_testFile.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_testFile.Location = new System.Drawing.Point(12, 25);
            this.txt_testFile.Name = "txt_testFile";
            this.txt_testFile.Size = new System.Drawing.Size(224, 20);
            this.txt_testFile.TabIndex = 2;
            this.txt_testFile.TextChanged += new System.EventHandler(this.txt_testFile_TextChanged);
            // 
            // btn_browseTestFile
            // 
            this.btn_browseTestFile.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_browseTestFile.Location = new System.Drawing.Point(242, 25);
            this.btn_browseTestFile.Name = "btn_browseTestFile";
            this.btn_browseTestFile.Size = new System.Drawing.Size(30, 20);
            this.btn_browseTestFile.TabIndex = 3;
            this.btn_browseTestFile.Text = "...";
            this.btn_browseTestFile.UseVisualStyleBackColor = true;
            this.btn_browseTestFile.Click += new System.EventHandler(this.btn_browseTestFile_Click);
            // 
            // lbl_outputFile
            // 
            this.lbl_outputFile.AutoSize = true;
            this.lbl_outputFile.Location = new System.Drawing.Point(12, 48);
            this.lbl_outputFile.Name = "lbl_outputFile";
            this.lbl_outputFile.Size = new System.Drawing.Size(58, 13);
            this.lbl_outputFile.TabIndex = 4;
            this.lbl_outputFile.Text = "Output file:";
            // 
            // txt_outputFile
            // 
            this.txt_outputFile.Anchor = ((System.Windows.Forms.AnchorStyles)(((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.txt_outputFile.Location = new System.Drawing.Point(12, 64);
            this.txt_outputFile.Name = "txt_outputFile";
            this.txt_outputFile.Size = new System.Drawing.Size(224, 20);
            this.txt_outputFile.TabIndex = 5;
            this.txt_outputFile.TextChanged += new System.EventHandler(this.txt_outputFile_TextChanged);
            // 
            // btn_browseOutputFile
            // 
            this.btn_browseOutputFile.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_browseOutputFile.Location = new System.Drawing.Point(242, 64);
            this.btn_browseOutputFile.Name = "btn_browseOutputFile";
            this.btn_browseOutputFile.Size = new System.Drawing.Size(30, 20);
            this.btn_browseOutputFile.TabIndex = 6;
            this.btn_browseOutputFile.Text = "...";
            this.btn_browseOutputFile.UseVisualStyleBackColor = true;
            this.btn_browseOutputFile.Click += new System.EventHandler(this.btn_browseOutputFile_Click);
            // 
            // btn_start
            // 
            this.btn_start.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.btn_start.Location = new System.Drawing.Point(197, 90);
            this.btn_start.Name = "btn_start";
            this.btn_start.Size = new System.Drawing.Size(75, 23);
            this.btn_start.TabIndex = 8;
            this.btn_start.Text = "Start";
            this.btn_start.UseVisualStyleBackColor = true;
            this.btn_start.Click += new System.EventHandler(this.btn_start_Click);
            // 
            // lbl_results
            // 
            this.lbl_results.AutoSize = true;
            this.lbl_results.Location = new System.Drawing.Point(12, 100);
            this.lbl_results.Name = "lbl_results";
            this.lbl_results.Size = new System.Drawing.Size(45, 13);
            this.lbl_results.TabIndex = 9;
            this.lbl_results.Text = "Results:";
            // 
            // watchTimer
            // 
            this.watchTimer.Interval = 10000;
            this.watchTimer.Tick += new System.EventHandler(this.watchTimer_Tick);
            // 
            // openFileDialog
            // 
            this.openFileDialog.FileName = "testFile";
            this.openFileDialog.Filter = "Executables|*.exe";
            this.openFileDialog.Title = "Select test file";
            // 
            // saveFileDialog
            // 
            this.saveFileDialog.DefaultExt = "xml";
            this.saveFileDialog.FileName = "test_results.xml";
            this.saveFileDialog.Filter = "XML files|*.xml";
            this.saveFileDialog.Title = "Select output file";
            // 
            // lbl_runtime
            // 
            this.lbl_runtime.AutoSize = true;
            this.lbl_runtime.Location = new System.Drawing.Point(63, 100);
            this.lbl_runtime.Name = "lbl_runtime";
            this.lbl_runtime.Size = new System.Drawing.Size(27, 13);
            this.lbl_runtime.TabIndex = 10;
            this.lbl_runtime.Text = "N/A";
            // 
            // notifyIcon
            // 
            this.notifyIcon.BalloonTipTitle = "AutoTester";
            this.notifyIcon.Icon = ((System.Drawing.Icon)(resources.GetObject("notifyIcon.Icon")));
            this.notifyIcon.Text = "AutoTester";
            this.notifyIcon.Visible = true;
            this.notifyIcon.Click += new System.EventHandler(this.notifyIcon_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 462);
            this.Controls.Add(this.lbl_runtime);
            this.Controls.Add(this.lbl_results);
            this.Controls.Add(this.btn_start);
            this.Controls.Add(this.btn_browseOutputFile);
            this.Controls.Add(this.txt_outputFile);
            this.Controls.Add(this.lbl_outputFile);
            this.Controls.Add(this.btn_browseTestFile);
            this.Controls.Add(this.txt_testFile);
            this.Controls.Add(this.lbl_test);
            this.Controls.Add(this.tree_results);
            this.Name = "MainForm";
            this.Text = "AutoTester";
            this.Load += new System.EventHandler(this.MainForm_Load);
            this.Resize += new System.EventHandler(this.MainForm_Resize);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TreeView tree_results;
        private System.Windows.Forms.Label lbl_test;
        private System.Windows.Forms.TextBox txt_testFile;
        private System.Windows.Forms.Button btn_browseTestFile;
        private System.Windows.Forms.Label lbl_outputFile;
        private System.Windows.Forms.TextBox txt_outputFile;
        private System.Windows.Forms.Button btn_browseOutputFile;
        private System.Windows.Forms.Button btn_start;
        private System.Windows.Forms.Label lbl_results;
        private System.Windows.Forms.Timer watchTimer;
        private System.Windows.Forms.OpenFileDialog openFileDialog;
        private System.Windows.Forms.SaveFileDialog saveFileDialog;
        private System.Windows.Forms.Label lbl_runtime;
        private System.Windows.Forms.NotifyIcon notifyIcon;
    }
}

