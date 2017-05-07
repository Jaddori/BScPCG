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
    QFrame *frame;
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
    QGroupBox *gb_seed;
    QLineEdit *txt_seed;
    QPushButton *btn_generate;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1060, 660);
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


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setMinimumSize(QSize(200, 642));
        frame->setMaximumSize(QSize(200, 1080));
        frame->setLayoutDirection(Qt::LeftToRight);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gb_district1 = new QGroupBox(frame);
        gb_district1->setObjectName(QStringLiteral("gb_district1"));
        gb_district1->setGeometry(QRect(0, 50, 200, 180));
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
        gb_district2 = new QGroupBox(frame);
        gb_district2->setObjectName(QStringLiteral("gb_district2"));
        gb_district2->setGeometry(QRect(0, 230, 200, 180));
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
        gb_district3 = new QGroupBox(frame);
        gb_district3->setObjectName(QStringLiteral("gb_district3"));
        gb_district3->setGeometry(QRect(0, 410, 200, 180));
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
        gb_seed = new QGroupBox(frame);
        gb_seed->setObjectName(QStringLiteral("gb_seed"));
        gb_seed->setGeometry(QRect(0, 0, 200, 50));
        txt_seed = new QLineEdit(gb_seed);
        txt_seed->setObjectName(QStringLiteral("txt_seed"));
        txt_seed->setGeometry(QRect(20, 20, 160, 20));
        txt_seed->setMaxLength(20);
        txt_seed->setClearButtonEnabled(false);
        btn_generate = new QPushButton(frame);
        btn_generate->setObjectName(QStringLiteral("btn_generate"));
        btn_generate->setGeometry(QRect(20, 600, 160, 30));

        gridLayout->addWidget(frame, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        gb_district1->setTitle(QApplication::translate("MainWindow", "District 1", Q_NULLPTR));
        lbl_d1MinHeight->setText(QApplication::translate("MainWindow", "Min. Height:", Q_NULLPTR));
        lbl_d1MaxHeight->setText(QApplication::translate("MainWindow", "Max. Height:", Q_NULLPTR));
        lbl_d1Density->setText(QApplication::translate("MainWindow", "Density:", Q_NULLPTR));
        lbl_d1MinHeightValue->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        lbl_d1MaxHeightValue->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        lbl_d1DensityValue->setText(QApplication::translate("MainWindow", "100%", Q_NULLPTR));
        gb_district2->setTitle(QApplication::translate("MainWindow", "District 2", Q_NULLPTR));
        lbl_d2MinHeight->setText(QApplication::translate("MainWindow", "Min. Height:", Q_NULLPTR));
        lbl_d2MaxHeight->setText(QApplication::translate("MainWindow", "Max. Height:", Q_NULLPTR));
        lbl_d2Density->setText(QApplication::translate("MainWindow", "Density:", Q_NULLPTR));
        lbl_d2MinHeightValue->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        lbl_d2MaxHeightValue->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        lbl_d2DensityValue->setText(QApplication::translate("MainWindow", "100%", Q_NULLPTR));
        gb_district3->setTitle(QApplication::translate("MainWindow", "District 3", Q_NULLPTR));
        lbl_d3MinHeight->setText(QApplication::translate("MainWindow", "Min. Height:", Q_NULLPTR));
        lbl_d3MaxHeight->setText(QApplication::translate("MainWindow", "Max. Height:", Q_NULLPTR));
        lbl_d3Density->setText(QApplication::translate("MainWindow", "Density:", Q_NULLPTR));
        lbl_d3MinHeightValue->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        lbl_d3MaxHeightValue->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        lbl_d3DensityValue->setText(QApplication::translate("MainWindow", "100%", Q_NULLPTR));
        gb_seed->setTitle(QApplication::translate("MainWindow", "Seed", Q_NULLPTR));
        btn_generate->setText(QApplication::translate("MainWindow", "Generate", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
