/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    GLWidget *glWidget;
    QFrame *frame_parameters;
    QGroupBox *gb_district1;
    QLabel *lbl_d1MinHeight;
    QSlider *slider_d1MinHeight;
    QLabel *lbl_d1MaxHeight;
    QSlider *slider_d1MaxHeight;
    QLabel *lbl_d1Density;
    QSlider *slider_d1Density;
    QLabel *lbl_d1MinHeightValue;
    QLabel *lbl_d1MaxHeightValue;
    QLabel *lbl_d1DensityValue;
    QLabel *lbl_d1BlockSize;
    QLabel *lbl_d1BlockSizeValue;
    QSlider *slider_d1BlockSize;
    QGroupBox *gb_district2;
    QLabel *lbl_d2MinHeight;
    QLabel *lbl_d2MaxHeight;
    QLabel *lbl_d2Density;
    QSlider *slider_d2MinHeight;
    QSlider *slider_d2MaxHeight;
    QSlider *slider_d2Density;
    QLabel *lbl_d2MinHeightValue;
    QLabel *lbl_d2MaxHeightValue;
    QLabel *lbl_d2DensityValue;
    QLabel *lbl_d2BlockSize;
    QLabel *lbl_d2BlockSizeValue;
    QSlider *slider_d2BlockSize;
    QGroupBox *gb_district3;
    QLabel *lbl_d3MinHeight;
    QLabel *lbl_d3MaxHeight;
    QLabel *lbl_d3Density;
    QSlider *slider_d3MinHeight;
    QSlider *slider_d3MaxHeight;
    QSlider *slider_d3Density;
    QLabel *lbl_d3MinHeightValue;
    QLabel *lbl_d3MaxHeightValue;
    QLabel *lbl_d3DensityValue;
    QLabel *lbl_d3BlockSize;
    QLabel *lbl_d3BlockSizeValue;
    QSlider *slider_d3BlockSize;
    QGroupBox *gb_seed;
    QLineEdit *txt_seed;
    QPushButton *btn_generate;
    QFrame *frame_info;
    QGroupBox *gb_statistics;
    QLabel *lbl_perlinCalls;
    QLabel *lbl_mainRoads;
    QLabel *lbl_smallRoads;
    QLabel *lbl_d1Buildings;
    QLabel *lbl_d2Buildings;
    QLabel *lbl_d3Buildings;
    QLabel *lbl_totalBuildings;
    QLabel *lbl_d1Grass;
    QLabel *lbl_d2Grass;
    QLabel *lbl_d3Grass;
    QLabel *lbl_totalGrass;
    QLabel *lbl_perlinCallsValue;
    QLabel *lbl_mainRoadsValue;
    QLabel *lbl_smallRoadsValue;
    QLabel *lbl_d1BuildingsValue;
    QLabel *lbl_d2BuildingsValue;
    QLabel *lbl_d3BuildingsValue;
    QLabel *lbl_totalBuildingsValue;
    QLabel *lbl_d1GrassValue;
    QLabel *lbl_d2GrassValue;
    QLabel *lbl_d3GrassValue;
    QLabel *lbl_totalGrassValue;
    QLabel *lbl_integerSeed;
    QLabel *lbl_integerSeedValue;
    QLabel *lbl_generationTime;
    QLabel *lbl_generationTimeValue;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1060, 780);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        glWidget = new GLWidget(centralWidget);
        glWidget->setObjectName(QStringLiteral("glWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(glWidget->sizePolicy().hasHeightForWidth());
        glWidget->setSizePolicy(sizePolicy);
        glWidget->setMouseTracking(false);
        glWidget->setFocusPolicy(Qt::ClickFocus);
        glWidget->setAutoFillBackground(false);

        horizontalLayout->addWidget(glWidget);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        frame_parameters = new QFrame(centralWidget);
        frame_parameters->setObjectName(QStringLiteral("frame_parameters"));
        sizePolicy.setHeightForWidth(frame_parameters->sizePolicy().hasHeightForWidth());
        frame_parameters->setSizePolicy(sizePolicy);
        frame_parameters->setMinimumSize(QSize(200, 642));
        frame_parameters->setMaximumSize(QSize(200, 1080));
        frame_parameters->setLayoutDirection(Qt::LeftToRight);
        frame_parameters->setFrameShape(QFrame::StyledPanel);
        frame_parameters->setFrameShadow(QFrame::Raised);
        gb_district1 = new QGroupBox(frame_parameters);
        gb_district1->setObjectName(QStringLiteral("gb_district1"));
        gb_district1->setGeometry(QRect(0, 50, 200, 220));
        lbl_d1MinHeight = new QLabel(gb_district1);
        lbl_d1MinHeight->setObjectName(QStringLiteral("lbl_d1MinHeight"));
        lbl_d1MinHeight->setGeometry(QRect(20, 20, 60, 13));
        slider_d1MinHeight = new QSlider(gb_district1);
        slider_d1MinHeight->setObjectName(QStringLiteral("slider_d1MinHeight"));
        slider_d1MinHeight->setGeometry(QRect(20, 40, 160, 19));
        slider_d1MinHeight->setMinimum(1);
        slider_d1MinHeight->setMaximum(10);
        slider_d1MinHeight->setOrientation(Qt::Horizontal);
        slider_d1MinHeight->setTickPosition(QSlider::TicksAbove);
        slider_d1MinHeight->setTickInterval(1);
        lbl_d1MaxHeight = new QLabel(gb_district1);
        lbl_d1MaxHeight->setObjectName(QStringLiteral("lbl_d1MaxHeight"));
        lbl_d1MaxHeight->setGeometry(QRect(20, 70, 60, 13));
        slider_d1MaxHeight = new QSlider(gb_district1);
        slider_d1MaxHeight->setObjectName(QStringLiteral("slider_d1MaxHeight"));
        slider_d1MaxHeight->setGeometry(QRect(20, 90, 160, 19));
        slider_d1MaxHeight->setMinimum(1);
        slider_d1MaxHeight->setMaximum(10);
        slider_d1MaxHeight->setSliderPosition(2);
        slider_d1MaxHeight->setOrientation(Qt::Horizontal);
        slider_d1MaxHeight->setTickPosition(QSlider::TicksAbove);
        slider_d1MaxHeight->setTickInterval(1);
        lbl_d1Density = new QLabel(gb_district1);
        lbl_d1Density->setObjectName(QStringLiteral("lbl_d1Density"));
        lbl_d1Density->setGeometry(QRect(20, 120, 60, 13));
        slider_d1Density = new QSlider(gb_district1);
        slider_d1Density->setObjectName(QStringLiteral("slider_d1Density"));
        slider_d1Density->setGeometry(QRect(20, 140, 160, 19));
        slider_d1Density->setMinimum(1);
        slider_d1Density->setMaximum(10);
        slider_d1Density->setSliderPosition(10);
        slider_d1Density->setOrientation(Qt::Horizontal);
        slider_d1Density->setTickPosition(QSlider::TicksAbove);
        slider_d1Density->setTickInterval(1);
        lbl_d1MinHeightValue = new QLabel(gb_district1);
        lbl_d1MinHeightValue->setObjectName(QStringLiteral("lbl_d1MinHeightValue"));
        lbl_d1MinHeightValue->setGeometry(QRect(90, 20, 60, 13));
        lbl_d1MaxHeightValue = new QLabel(gb_district1);
        lbl_d1MaxHeightValue->setObjectName(QStringLiteral("lbl_d1MaxHeightValue"));
        lbl_d1MaxHeightValue->setGeometry(QRect(90, 70, 47, 13));
        lbl_d1DensityValue = new QLabel(gb_district1);
        lbl_d1DensityValue->setObjectName(QStringLiteral("lbl_d1DensityValue"));
        lbl_d1DensityValue->setGeometry(QRect(90, 120, 47, 13));
        lbl_d1BlockSize = new QLabel(gb_district1);
        lbl_d1BlockSize->setObjectName(QStringLiteral("lbl_d1BlockSize"));
        lbl_d1BlockSize->setGeometry(QRect(20, 170, 60, 13));
        lbl_d1BlockSizeValue = new QLabel(gb_district1);
        lbl_d1BlockSizeValue->setObjectName(QStringLiteral("lbl_d1BlockSizeValue"));
        lbl_d1BlockSizeValue->setGeometry(QRect(90, 170, 47, 13));
        slider_d1BlockSize = new QSlider(gb_district1);
        slider_d1BlockSize->setObjectName(QStringLiteral("slider_d1BlockSize"));
        slider_d1BlockSize->setGeometry(QRect(20, 190, 160, 19));
        slider_d1BlockSize->setMinimum(1);
        slider_d1BlockSize->setMaximum(10);
        slider_d1BlockSize->setSliderPosition(2);
        slider_d1BlockSize->setOrientation(Qt::Horizontal);
        slider_d1BlockSize->setInvertedAppearance(false);
        slider_d1BlockSize->setInvertedControls(false);
        slider_d1BlockSize->setTickPosition(QSlider::TicksAbove);
        slider_d1BlockSize->setTickInterval(1);
        gb_district2 = new QGroupBox(frame_parameters);
        gb_district2->setObjectName(QStringLiteral("gb_district2"));
        gb_district2->setGeometry(QRect(0, 270, 200, 220));
        lbl_d2MinHeight = new QLabel(gb_district2);
        lbl_d2MinHeight->setObjectName(QStringLiteral("lbl_d2MinHeight"));
        lbl_d2MinHeight->setGeometry(QRect(20, 20, 60, 13));
        lbl_d2MaxHeight = new QLabel(gb_district2);
        lbl_d2MaxHeight->setObjectName(QStringLiteral("lbl_d2MaxHeight"));
        lbl_d2MaxHeight->setGeometry(QRect(20, 70, 60, 13));
        lbl_d2Density = new QLabel(gb_district2);
        lbl_d2Density->setObjectName(QStringLiteral("lbl_d2Density"));
        lbl_d2Density->setGeometry(QRect(20, 120, 60, 13));
        slider_d2MinHeight = new QSlider(gb_district2);
        slider_d2MinHeight->setObjectName(QStringLiteral("slider_d2MinHeight"));
        slider_d2MinHeight->setGeometry(QRect(20, 40, 160, 19));
        slider_d2MinHeight->setMinimum(1);
        slider_d2MinHeight->setMaximum(10);
        slider_d2MinHeight->setOrientation(Qt::Horizontal);
        slider_d2MinHeight->setTickPosition(QSlider::TicksAbove);
        slider_d2MinHeight->setTickInterval(1);
        slider_d2MaxHeight = new QSlider(gb_district2);
        slider_d2MaxHeight->setObjectName(QStringLiteral("slider_d2MaxHeight"));
        slider_d2MaxHeight->setGeometry(QRect(20, 90, 160, 19));
        slider_d2MaxHeight->setMinimum(1);
        slider_d2MaxHeight->setMaximum(10);
        slider_d2MaxHeight->setSliderPosition(2);
        slider_d2MaxHeight->setOrientation(Qt::Horizontal);
        slider_d2MaxHeight->setTickPosition(QSlider::TicksAbove);
        slider_d2MaxHeight->setTickInterval(1);
        slider_d2Density = new QSlider(gb_district2);
        slider_d2Density->setObjectName(QStringLiteral("slider_d2Density"));
        slider_d2Density->setGeometry(QRect(20, 140, 160, 19));
        slider_d2Density->setMinimum(1);
        slider_d2Density->setMaximum(10);
        slider_d2Density->setSingleStep(1);
        slider_d2Density->setSliderPosition(10);
        slider_d2Density->setOrientation(Qt::Horizontal);
        slider_d2Density->setTickPosition(QSlider::TicksAbove);
        slider_d2Density->setTickInterval(1);
        lbl_d2MinHeightValue = new QLabel(gb_district2);
        lbl_d2MinHeightValue->setObjectName(QStringLiteral("lbl_d2MinHeightValue"));
        lbl_d2MinHeightValue->setGeometry(QRect(90, 20, 47, 13));
        lbl_d2MaxHeightValue = new QLabel(gb_district2);
        lbl_d2MaxHeightValue->setObjectName(QStringLiteral("lbl_d2MaxHeightValue"));
        lbl_d2MaxHeightValue->setGeometry(QRect(90, 70, 47, 13));
        lbl_d2DensityValue = new QLabel(gb_district2);
        lbl_d2DensityValue->setObjectName(QStringLiteral("lbl_d2DensityValue"));
        lbl_d2DensityValue->setGeometry(QRect(90, 120, 47, 13));
        lbl_d2BlockSize = new QLabel(gb_district2);
        lbl_d2BlockSize->setObjectName(QStringLiteral("lbl_d2BlockSize"));
        lbl_d2BlockSize->setGeometry(QRect(20, 170, 60, 13));
        lbl_d2BlockSizeValue = new QLabel(gb_district2);
        lbl_d2BlockSizeValue->setObjectName(QStringLiteral("lbl_d2BlockSizeValue"));
        lbl_d2BlockSizeValue->setGeometry(QRect(90, 170, 47, 13));
        slider_d2BlockSize = new QSlider(gb_district2);
        slider_d2BlockSize->setObjectName(QStringLiteral("slider_d2BlockSize"));
        slider_d2BlockSize->setGeometry(QRect(20, 190, 160, 19));
        slider_d2BlockSize->setMinimum(1);
        slider_d2BlockSize->setMaximum(10);
        slider_d2BlockSize->setSliderPosition(2);
        slider_d2BlockSize->setOrientation(Qt::Horizontal);
        slider_d2BlockSize->setTickPosition(QSlider::TicksAbove);
        slider_d2BlockSize->setTickInterval(1);
        gb_district3 = new QGroupBox(frame_parameters);
        gb_district3->setObjectName(QStringLiteral("gb_district3"));
        gb_district3->setGeometry(QRect(0, 490, 200, 220));
        lbl_d3MinHeight = new QLabel(gb_district3);
        lbl_d3MinHeight->setObjectName(QStringLiteral("lbl_d3MinHeight"));
        lbl_d3MinHeight->setGeometry(QRect(20, 20, 60, 13));
        lbl_d3MaxHeight = new QLabel(gb_district3);
        lbl_d3MaxHeight->setObjectName(QStringLiteral("lbl_d3MaxHeight"));
        lbl_d3MaxHeight->setGeometry(QRect(20, 70, 60, 13));
        lbl_d3Density = new QLabel(gb_district3);
        lbl_d3Density->setObjectName(QStringLiteral("lbl_d3Density"));
        lbl_d3Density->setGeometry(QRect(20, 120, 60, 13));
        slider_d3MinHeight = new QSlider(gb_district3);
        slider_d3MinHeight->setObjectName(QStringLiteral("slider_d3MinHeight"));
        slider_d3MinHeight->setGeometry(QRect(20, 40, 160, 19));
        slider_d3MinHeight->setMinimum(1);
        slider_d3MinHeight->setMaximum(10);
        slider_d3MinHeight->setOrientation(Qt::Horizontal);
        slider_d3MinHeight->setTickPosition(QSlider::TicksAbove);
        slider_d3MinHeight->setTickInterval(1);
        slider_d3MaxHeight = new QSlider(gb_district3);
        slider_d3MaxHeight->setObjectName(QStringLiteral("slider_d3MaxHeight"));
        slider_d3MaxHeight->setGeometry(QRect(20, 90, 160, 19));
        slider_d3MaxHeight->setMinimum(1);
        slider_d3MaxHeight->setMaximum(10);
        slider_d3MaxHeight->setSliderPosition(2);
        slider_d3MaxHeight->setOrientation(Qt::Horizontal);
        slider_d3MaxHeight->setTickPosition(QSlider::TicksAbove);
        slider_d3MaxHeight->setTickInterval(1);
        slider_d3Density = new QSlider(gb_district3);
        slider_d3Density->setObjectName(QStringLiteral("slider_d3Density"));
        slider_d3Density->setGeometry(QRect(20, 140, 160, 19));
        slider_d3Density->setMinimum(1);
        slider_d3Density->setMaximum(10);
        slider_d3Density->setSliderPosition(10);
        slider_d3Density->setOrientation(Qt::Horizontal);
        slider_d3Density->setTickPosition(QSlider::TicksAbove);
        slider_d3Density->setTickInterval(1);
        lbl_d3MinHeightValue = new QLabel(gb_district3);
        lbl_d3MinHeightValue->setObjectName(QStringLiteral("lbl_d3MinHeightValue"));
        lbl_d3MinHeightValue->setGeometry(QRect(90, 20, 47, 13));
        lbl_d3MaxHeightValue = new QLabel(gb_district3);
        lbl_d3MaxHeightValue->setObjectName(QStringLiteral("lbl_d3MaxHeightValue"));
        lbl_d3MaxHeightValue->setGeometry(QRect(90, 70, 47, 13));
        lbl_d3DensityValue = new QLabel(gb_district3);
        lbl_d3DensityValue->setObjectName(QStringLiteral("lbl_d3DensityValue"));
        lbl_d3DensityValue->setGeometry(QRect(90, 120, 47, 13));
        lbl_d3BlockSize = new QLabel(gb_district3);
        lbl_d3BlockSize->setObjectName(QStringLiteral("lbl_d3BlockSize"));
        lbl_d3BlockSize->setGeometry(QRect(20, 170, 60, 13));
        lbl_d3BlockSizeValue = new QLabel(gb_district3);
        lbl_d3BlockSizeValue->setObjectName(QStringLiteral("lbl_d3BlockSizeValue"));
        lbl_d3BlockSizeValue->setGeometry(QRect(90, 170, 47, 13));
        slider_d3BlockSize = new QSlider(gb_district3);
        slider_d3BlockSize->setObjectName(QStringLiteral("slider_d3BlockSize"));
        slider_d3BlockSize->setGeometry(QRect(20, 190, 160, 19));
        slider_d3BlockSize->setMinimum(1);
        slider_d3BlockSize->setMaximum(10);
        slider_d3BlockSize->setSliderPosition(2);
        slider_d3BlockSize->setOrientation(Qt::Horizontal);
        slider_d3BlockSize->setTickPosition(QSlider::TicksAbove);
        slider_d3BlockSize->setTickInterval(1);
        gb_seed = new QGroupBox(frame_parameters);
        gb_seed->setObjectName(QStringLiteral("gb_seed"));
        gb_seed->setGeometry(QRect(0, 0, 200, 50));
        txt_seed = new QLineEdit(gb_seed);
        txt_seed->setObjectName(QStringLiteral("txt_seed"));
        txt_seed->setGeometry(QRect(20, 20, 160, 20));
        txt_seed->setMaxLength(20);
        txt_seed->setClearButtonEnabled(false);
        btn_generate = new QPushButton(frame_parameters);
        btn_generate->setObjectName(QStringLiteral("btn_generate"));
        btn_generate->setGeometry(QRect(20, 720, 160, 30));

        gridLayout->addWidget(frame_parameters, 0, 2, 1, 1);

        frame_info = new QFrame(centralWidget);
        frame_info->setObjectName(QStringLiteral("frame_info"));
        frame_info->setMinimumSize(QSize(100, 0));
        frame_info->setMaximumSize(QSize(100, 16777215));
        frame_info->setFrameShape(QFrame::StyledPanel);
        frame_info->setFrameShadow(QFrame::Raised);
        gb_statistics = new QGroupBox(frame_info);
        gb_statistics->setObjectName(QStringLiteral("gb_statistics"));
        gb_statistics->setGeometry(QRect(0, 0, 100, 760));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        gb_statistics->setFont(font);
        lbl_perlinCalls = new QLabel(gb_statistics);
        lbl_perlinCalls->setObjectName(QStringLiteral("lbl_perlinCalls"));
        lbl_perlinCalls->setGeometry(QRect(10, 20, 80, 13));
        lbl_mainRoads = new QLabel(gb_statistics);
        lbl_mainRoads->setObjectName(QStringLiteral("lbl_mainRoads"));
        lbl_mainRoads->setGeometry(QRect(10, 60, 80, 13));
        lbl_smallRoads = new QLabel(gb_statistics);
        lbl_smallRoads->setObjectName(QStringLiteral("lbl_smallRoads"));
        lbl_smallRoads->setGeometry(QRect(10, 100, 80, 13));
        lbl_d1Buildings = new QLabel(gb_statistics);
        lbl_d1Buildings->setObjectName(QStringLiteral("lbl_d1Buildings"));
        lbl_d1Buildings->setGeometry(QRect(10, 140, 80, 13));
        lbl_d2Buildings = new QLabel(gb_statistics);
        lbl_d2Buildings->setObjectName(QStringLiteral("lbl_d2Buildings"));
        lbl_d2Buildings->setGeometry(QRect(10, 180, 80, 13));
        lbl_d3Buildings = new QLabel(gb_statistics);
        lbl_d3Buildings->setObjectName(QStringLiteral("lbl_d3Buildings"));
        lbl_d3Buildings->setGeometry(QRect(10, 220, 80, 13));
        lbl_totalBuildings = new QLabel(gb_statistics);
        lbl_totalBuildings->setObjectName(QStringLiteral("lbl_totalBuildings"));
        lbl_totalBuildings->setGeometry(QRect(10, 260, 80, 13));
        lbl_d1Grass = new QLabel(gb_statistics);
        lbl_d1Grass->setObjectName(QStringLiteral("lbl_d1Grass"));
        lbl_d1Grass->setGeometry(QRect(10, 300, 80, 13));
        lbl_d2Grass = new QLabel(gb_statistics);
        lbl_d2Grass->setObjectName(QStringLiteral("lbl_d2Grass"));
        lbl_d2Grass->setGeometry(QRect(10, 340, 80, 13));
        lbl_d3Grass = new QLabel(gb_statistics);
        lbl_d3Grass->setObjectName(QStringLiteral("lbl_d3Grass"));
        lbl_d3Grass->setGeometry(QRect(10, 380, 80, 13));
        lbl_totalGrass = new QLabel(gb_statistics);
        lbl_totalGrass->setObjectName(QStringLiteral("lbl_totalGrass"));
        lbl_totalGrass->setGeometry(QRect(10, 420, 80, 13));
        lbl_totalGrass->setFont(font);
        lbl_perlinCallsValue = new QLabel(gb_statistics);
        lbl_perlinCallsValue->setObjectName(QStringLiteral("lbl_perlinCallsValue"));
        lbl_perlinCallsValue->setGeometry(QRect(10, 40, 80, 13));
        lbl_mainRoadsValue = new QLabel(gb_statistics);
        lbl_mainRoadsValue->setObjectName(QStringLiteral("lbl_mainRoadsValue"));
        lbl_mainRoadsValue->setGeometry(QRect(10, 80, 80, 13));
        lbl_smallRoadsValue = new QLabel(gb_statistics);
        lbl_smallRoadsValue->setObjectName(QStringLiteral("lbl_smallRoadsValue"));
        lbl_smallRoadsValue->setGeometry(QRect(10, 120, 80, 13));
        lbl_d1BuildingsValue = new QLabel(gb_statistics);
        lbl_d1BuildingsValue->setObjectName(QStringLiteral("lbl_d1BuildingsValue"));
        lbl_d1BuildingsValue->setGeometry(QRect(10, 160, 80, 13));
        lbl_d2BuildingsValue = new QLabel(gb_statistics);
        lbl_d2BuildingsValue->setObjectName(QStringLiteral("lbl_d2BuildingsValue"));
        lbl_d2BuildingsValue->setGeometry(QRect(10, 200, 80, 13));
        lbl_d3BuildingsValue = new QLabel(gb_statistics);
        lbl_d3BuildingsValue->setObjectName(QStringLiteral("lbl_d3BuildingsValue"));
        lbl_d3BuildingsValue->setGeometry(QRect(10, 240, 80, 13));
        lbl_totalBuildingsValue = new QLabel(gb_statistics);
        lbl_totalBuildingsValue->setObjectName(QStringLiteral("lbl_totalBuildingsValue"));
        lbl_totalBuildingsValue->setGeometry(QRect(10, 280, 80, 13));
        lbl_d1GrassValue = new QLabel(gb_statistics);
        lbl_d1GrassValue->setObjectName(QStringLiteral("lbl_d1GrassValue"));
        lbl_d1GrassValue->setGeometry(QRect(10, 320, 80, 13));
        lbl_d2GrassValue = new QLabel(gb_statistics);
        lbl_d2GrassValue->setObjectName(QStringLiteral("lbl_d2GrassValue"));
        lbl_d2GrassValue->setGeometry(QRect(10, 360, 80, 13));
        lbl_d3GrassValue = new QLabel(gb_statistics);
        lbl_d3GrassValue->setObjectName(QStringLiteral("lbl_d3GrassValue"));
        lbl_d3GrassValue->setGeometry(QRect(10, 400, 80, 13));
        lbl_totalGrassValue = new QLabel(gb_statistics);
        lbl_totalGrassValue->setObjectName(QStringLiteral("lbl_totalGrassValue"));
        lbl_totalGrassValue->setGeometry(QRect(10, 440, 80, 13));
        lbl_integerSeed = new QLabel(gb_statistics);
        lbl_integerSeed->setObjectName(QStringLiteral("lbl_integerSeed"));
        lbl_integerSeed->setGeometry(QRect(10, 460, 80, 13));
        lbl_integerSeedValue = new QLabel(gb_statistics);
        lbl_integerSeedValue->setObjectName(QStringLiteral("lbl_integerSeedValue"));
        lbl_integerSeedValue->setGeometry(QRect(10, 480, 80, 13));
        lbl_generationTime = new QLabel(gb_statistics);
        lbl_generationTime->setObjectName(QStringLiteral("lbl_generationTime"));
        lbl_generationTime->setGeometry(QRect(10, 500, 80, 13));
        lbl_generationTimeValue = new QLabel(gb_statistics);
        lbl_generationTimeValue->setObjectName(QStringLiteral("lbl_generationTimeValue"));
        lbl_generationTimeValue->setGeometry(QRect(10, 520, 80, 13));

        gridLayout->addWidget(frame_info, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        gb_district1->setTitle(QApplication::translate("MainWindow", "Houses", Q_NULLPTR));
        lbl_d1MinHeight->setText(QApplication::translate("MainWindow", "Min. Height:", Q_NULLPTR));
        lbl_d1MaxHeight->setText(QApplication::translate("MainWindow", "Max. Height:", Q_NULLPTR));
        lbl_d1Density->setText(QApplication::translate("MainWindow", "Density:", Q_NULLPTR));
        lbl_d1MinHeightValue->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        lbl_d1MaxHeightValue->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        lbl_d1DensityValue->setText(QApplication::translate("MainWindow", "100%", Q_NULLPTR));
        lbl_d1BlockSize->setText(QApplication::translate("MainWindow", "Block Size:", Q_NULLPTR));
        lbl_d1BlockSizeValue->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        gb_district2->setTitle(QApplication::translate("MainWindow", "Skyscrapers", Q_NULLPTR));
        lbl_d2MinHeight->setText(QApplication::translate("MainWindow", "Min. Height:", Q_NULLPTR));
        lbl_d2MaxHeight->setText(QApplication::translate("MainWindow", "Max. Height:", Q_NULLPTR));
        lbl_d2Density->setText(QApplication::translate("MainWindow", "Density:", Q_NULLPTR));
        lbl_d2MinHeightValue->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        lbl_d2MaxHeightValue->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        lbl_d2DensityValue->setText(QApplication::translate("MainWindow", "100%", Q_NULLPTR));
        lbl_d2BlockSize->setText(QApplication::translate("MainWindow", "Block Size:", Q_NULLPTR));
        lbl_d2BlockSizeValue->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        gb_district3->setTitle(QApplication::translate("MainWindow", "Factories", Q_NULLPTR));
        lbl_d3MinHeight->setText(QApplication::translate("MainWindow", "Min. Height:", Q_NULLPTR));
        lbl_d3MaxHeight->setText(QApplication::translate("MainWindow", "Max. Height:", Q_NULLPTR));
        lbl_d3Density->setText(QApplication::translate("MainWindow", "Density:", Q_NULLPTR));
        lbl_d3MinHeightValue->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        lbl_d3MaxHeightValue->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        lbl_d3DensityValue->setText(QApplication::translate("MainWindow", "100%", Q_NULLPTR));
        lbl_d3BlockSize->setText(QApplication::translate("MainWindow", "Block Size:", Q_NULLPTR));
        lbl_d3BlockSizeValue->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        gb_seed->setTitle(QApplication::translate("MainWindow", "Seed", Q_NULLPTR));
        btn_generate->setText(QApplication::translate("MainWindow", "Generate", Q_NULLPTR));
        gb_statistics->setTitle(QApplication::translate("MainWindow", "Statistics", Q_NULLPTR));
        lbl_perlinCalls->setText(QApplication::translate("MainWindow", "Perlin calls:", Q_NULLPTR));
        lbl_mainRoads->setText(QApplication::translate("MainWindow", "Main roads:", Q_NULLPTR));
        lbl_smallRoads->setText(QApplication::translate("MainWindow", "Small roads:", Q_NULLPTR));
        lbl_d1Buildings->setText(QApplication::translate("MainWindow", "Houses:", Q_NULLPTR));
        lbl_d2Buildings->setText(QApplication::translate("MainWindow", "Skyscrapers:", Q_NULLPTR));
        lbl_d3Buildings->setText(QApplication::translate("MainWindow", "Factories:", Q_NULLPTR));
        lbl_totalBuildings->setText(QApplication::translate("MainWindow", "Total buildings:", Q_NULLPTR));
        lbl_d1Grass->setText(QApplication::translate("MainWindow", "D1 grass:", Q_NULLPTR));
        lbl_d2Grass->setText(QApplication::translate("MainWindow", "D2 grass:", Q_NULLPTR));
        lbl_d3Grass->setText(QApplication::translate("MainWindow", "D3 grass:", Q_NULLPTR));
        lbl_totalGrass->setText(QApplication::translate("MainWindow", "Total grass:", Q_NULLPTR));
        lbl_perlinCallsValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_mainRoadsValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_smallRoadsValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_d1BuildingsValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_d2BuildingsValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_d3BuildingsValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_totalBuildingsValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_d1GrassValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_d2GrassValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_d3GrassValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_totalGrassValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_integerSeed->setText(QApplication::translate("MainWindow", "Integer seed:", Q_NULLPTR));
        lbl_integerSeedValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        lbl_generationTime->setText(QApplication::translate("MainWindow", "Generation time:", Q_NULLPTR));
        lbl_generationTimeValue->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
