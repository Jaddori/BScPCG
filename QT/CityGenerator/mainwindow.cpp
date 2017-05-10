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
    clock_t startTime = clock();

    // generate city based on user input
    CityParameters parameters;

    QString seedString = ui->txt_seed->text();
    std::string utf8Seed = seedString.toUtf8().constData();
    seedConverter.setSeed(utf8Seed);

    parameters.seed = seedConverter.getIntegerSeed();

    parameters.minHeights[0] = ui->slider_d1MinHeight->value();
    parameters.maxHeights[0] = ui->slider_d1MaxHeight->value();
    parameters.densities[0] = (float)ui->slider_d1Density->value() * 0.1f; // transform from 0-10 -> 0-1
    parameters.blockSizes[0] = ui->slider_d1BlockSize->value();

    parameters.minHeights[1] = ui->slider_d2MinHeight->value();
    parameters.maxHeights[1] = ui->slider_d2MaxHeight->value();
    parameters.densities[1] = (float)ui->slider_d2Density->value() * 0.1f;
    parameters.blockSizes[1] = ui->slider_d2BlockSize->value();

    parameters.minHeights[2] = ui->slider_d3MinHeight->value();
    parameters.maxHeights[2] = ui->slider_d3MaxHeight->value();
    parameters.densities[2] = (float)ui->slider_d3Density->value() * 0.1f;
    parameters.blockSizes[2] = ui->slider_d3BlockSize->value();

    ui->glWidget->generate(parameters);

    float timeElapsed = (float)(clock() - startTime) / (float)CLOCKS_PER_SEC;

    // collect statistics
    Elicras& elicras = ui->glWidget->getElicras();

    ui->lbl_perlinCallsValue->setText(QString::number(elicras.getStatistic("perlinNoise")));

    ui->lbl_mainRoadsValue->setText(QString::number(elicras.getStatistic("mainRoads")));
    ui->lbl_smallRoadsValue->setText(QString::number(elicras.getStatistic("smallRoads")));

    ui->lbl_d1BuildingsValue->setText(QString::number(elicras.getStatistic("district1Buildings")));
    ui->lbl_d2BuildingsValue->setText(QString::number(elicras.getStatistic("district2Buildings")));
    ui->lbl_d3BuildingsValue->setText(QString::number(elicras.getStatistic("district3Buildings")));
    ui->lbl_totalBuildingsValue->setText(QString::number(elicras.getStatistic("totalBuildings")));

    ui->lbl_d1GrassValue->setText(QString::number(elicras.getStatistic("district1Grass")));
    ui->lbl_d2GrassValue->setText(QString::number(elicras.getStatistic("district2Grass")));
    ui->lbl_d3GrassValue->setText(QString::number(elicras.getStatistic("district3Grass")));
    ui->lbl_totalGrassValue->setText(QString::number(elicras.getStatistic("totalGrass")));

    ui->lbl_integerSeedValue->setText(QString::number(parameters.seed));
    ui->lbl_generationTimeValue->setText(QString::number(timeElapsed) + QString("s"));
}

void MainWindow::on_slider_d1MinHeight_valueChanged(int value)
{
    if(ui->slider_d1MaxHeight->value() <= value)
    {
        ui->slider_d1MaxHeight->setValue(value+1);
    }

    ui->lbl_d1MinHeightValue->setText(QString::number(value));
}

void MainWindow::on_slider_d2MinHeight_valueChanged(int value)
{
    if(ui->slider_d2MaxHeight->value() <= value)
    {
        ui->slider_d2MaxHeight->setValue(value+1);
    }

    ui->lbl_d2MinHeightValue->setText(QString::number(value));
}

void MainWindow::on_slider_d3MinHeight_valueChanged(int value)
{
    if(ui->slider_d3MaxHeight->value() <= value)
    {
        ui->slider_d3MaxHeight->setValue(value+1);
    }

    ui->lbl_d3MinHeightValue->setText(QString::number(value));
}

void MainWindow::on_slider_d1MaxHeight_valueChanged(int value)
{
    if(value <= ui->slider_d1MinHeight->value())
    {
        ui->slider_d1MaxHeight->setValue(ui->slider_d1MinHeight->value());
    }
    else
    {
        ui->lbl_d1MaxHeightValue->setText(QString::number(value));
    }
}

void MainWindow::on_slider_d2MaxHeight_valueChanged(int value)
{
    if(value <= ui->slider_d2MinHeight->value())
    {
        ui->slider_d2MaxHeight->setValue(ui->slider_d2MinHeight->value());
    }
    else
    {
        ui->lbl_d2MaxHeightValue->setText(QString::number(value));
    }
}

void MainWindow::on_slider_d3MaxHeight_valueChanged(int value)
{
    if(value <= ui->slider_d3MinHeight->value())
    {
        ui->slider_d3MaxHeight->setValue(ui->slider_d3MinHeight->value());
    }
    else
    {
        ui->lbl_d3MaxHeightValue->setText(QString::number(value));
    }
}

void MainWindow::on_slider_d1Density_valueChanged(int value)
{
    ui->lbl_d1DensityValue->setText(QString::number(value*10) + QString("%"));
}

void MainWindow::on_slider_d2Density_valueChanged(int value)
{
    ui->lbl_d2DensityValue->setText(QString::number(value*10) + QString("%"));
}

void MainWindow::on_slider_d3Density_valueChanged(int value)
{
    ui->lbl_d3DensityValue->setText(QString::number(value*10) + QString("%"));
}

void MainWindow::on_slider_d1BlockSize_valueChanged(int value)
{
    ui->lbl_d1BlockSizeValue->setText(QString::number(value));
}

void MainWindow::on_slider_d2BlockSize_valueChanged(int value)
{
    ui->lbl_d2BlockSizeValue->setText(QString::number(value));
}

void MainWindow::on_slider_d3BlockSize_valueChanged(int value)
{
    ui->lbl_d3BlockSizeValue->setText(QString::number(value));
}

void MainWindow::on_btn_resetCamera_clicked()
{
    ui->glWidget->resetCamera();
}
