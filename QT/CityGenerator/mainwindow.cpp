#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btn_generate_clicked()
{
    CityParameters parameters;

    QString seedString = ui->txt_seed->text();
    std::string utf8Seed = seedString.toUtf8().constData();
    seedConverter.setSeed(utf8Seed);

    parameters.seed = seedConverter.getIntegerSeed();

    parameters.minHeights[0] = ui->slider_d1MinHeight->value();
    parameters.maxHeights[0] = ui->slider_d1MaxHeight->value();
    parameters.blockSizes[0] = ui->slider_d1BlockSize->value();

    parameters.minHeights[1] = ui->slider_d2MinHeight->value();
    parameters.maxHeights[1] = ui->slider_d2MaxHeight->value();
    parameters.blockSizes[1] = ui->slider_d2BlockSize->value();

    parameters.minHeights[2] = ui->slider_d3MinHeight->value();
    parameters.maxHeights[2] = ui->slider_d3MaxHeight->value();
    parameters.blockSizes[2] = ui->slider_d3BlockSize->value();

    ui->glWidget->generate(parameters);
}
