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
    QLabel *lbl_d1BlockSize;
    QSlider *slider_d1BlockSize;
    QGroupBox *gb_district2;
    QLabel *lbl_d2MinHeight;
    QLabel *lbl_d2MaxHeight;
    QLabel *lbl_d2BlockSize;
    QSlider *slider_d2MinHeight;
    QSlider *slider_d2MaxHeight;
    QSlider *slider_d2BlockSize;
    QGroupBox *gb_district3;
    QLabel *lbl_d3MinHeight;
    QLabel *lbl_d3MaxHeight;
    QLabel *lbl_d3BlockSize;
    QSlider *slider_d3MinHeight;
    QSlider *slider_d3MaxHeight;
    QSlider *slider_d3BlockSize;
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
        lbl_d1MinHeight->setGeometry(QRect(20, 20, 160, 13));
        slider_d1MinHeight = new QSlider(gb_district1);
        slider_d1MinHeight->setObjectName(QStringLiteral("slider_d1MinHeight"));
        slider_d1MinHeight->setGeometry(QRect(20, 40, 160, 19));
        slider_d1MinHeight->setMinimum(1);
        slider_d1MinHeight->setMaximum(20);
        slider_d1MinHeight->setOrientation(Qt::Horizontal);
        slider_d1MinHeight->setTickPosition(QSlider::TicksAbove);
        slider_d1MinHeight->setTickInterval(1);
        lbl_d1MaxHeight = new QLabel(gb_district1);
        lbl_d1MaxHeight->setObjectName(QStringLiteral("lbl_d1MaxHeight"));
        lbl_d1MaxHeight->setGeometry(QRect(20, 70, 160, 13));
        slider_d1MaxHeight = new QSlider(gb_district1);
        slider_d1MaxHeight->setObjectName(QStringLiteral("slider_d1MaxHeight"));
        slider_d1MaxHeight->setGeometry(QRect(20, 90, 160, 19));
        slider_d1MaxHeight->setMinimum(1);
        slider_d1MaxHeight->setMaximum(20);
        slider_d1MaxHeight->setOrientation(Qt::Horizontal);
        slider_d1MaxHeight->setTickPosition(QSlider::TicksAbove);
        slider_d1MaxHeight->setTickInterval(1);
        lbl_d1BlockSize = new QLabel(gb_district1);
        lbl_d1BlockSize->setObjectName(QStringLiteral("lbl_d1BlockSize"));
        lbl_d1BlockSize->setGeometry(QRect(20, 120, 160, 13));
        slider_d1BlockSize = new QSlider(gb_district1);
        slider_d1BlockSize->setObjectName(QStringLiteral("slider_d1BlockSize"));
        slider_d1BlockSize->setGeometry(QRect(20, 140, 160, 19));
        slider_d1BlockSize->setMinimum(1);
        slider_d1BlockSize->setMaximum(20);
        slider_d1BlockSize->setOrientation(Qt::Horizontal);
        slider_d1BlockSize->setTickPosition(QSlider::TicksAbove);
        slider_d1BlockSize->setTickInterval(1);
        gb_district2 = new QGroupBox(frame);
        gb_district2->setObjectName(QStringLiteral("gb_district2"));
        gb_district2->setGeometry(QRect(0, 230, 200, 180));
        lbl_d2MinHeight = new QLabel(gb_district2);
        lbl_d2MinHeight->setObjectName(QStringLiteral("lbl_d2MinHeight"));
        lbl_d2MinHeight->setGeometry(QRect(20, 20, 160, 13));
        lbl_d2MaxHeight = new QLabel(gb_district2);
        lbl_d2MaxHeight->setObjectName(QStringLiteral("lbl_d2MaxHeight"));
        lbl_d2MaxHeight->setGeometry(QRect(20, 70, 160, 13));
        lbl_d2BlockSize = new QLabel(gb_district2);
        lbl_d2BlockSize->setObjectName(QStringLiteral("lbl_d2BlockSize"));
        lbl_d2BlockSize->setGeometry(QRect(20, 120, 160, 13));
        slider_d2MinHeight = new QSlider(gb_district2);
        slider_d2MinHeight->setObjectName(QStringLiteral("slider_d2MinHeight"));
        slider_d2MinHeight->setGeometry(QRect(20, 40, 160, 19));
        slider_d2MinHeight->setMinimum(1);
        slider_d2MinHeight->setMaximum(20);
        slider_d2MinHeight->setOrientation(Qt::Horizontal);
        slider_d2MinHeight->setTickPosition(QSlider::TicksAbove);
        slider_d2MinHeight->setTickInterval(1);
        slider_d2MaxHeight = new QSlider(gb_district2);
        slider_d2MaxHeight->setObjectName(QStringLiteral("slider_d2MaxHeight"));
        slider_d2MaxHeight->setGeometry(QRect(20, 90, 160, 19));
        slider_d2MaxHeight->setMinimum(1);
        slider_d2MaxHeight->setMaximum(20);
        slider_d2MaxHeight->setOrientation(Qt::Horizontal);
        slider_d2MaxHeight->setTickPosition(QSlider::TicksAbove);
        slider_d2MaxHeight->setTickInterval(1);
        slider_d2BlockSize = new QSlider(gb_district2);
        slider_d2BlockSize->setObjectName(QStringLiteral("slider_d2BlockSize"));
        slider_d2BlockSize->setGeometry(QRect(20, 140, 160, 19));
        slider_d2BlockSize->setMinimum(1);
        slider_d2BlockSize->setMaximum(20);
        slider_d2BlockSize->setOrientation(Qt::Horizontal);
        slider_d2BlockSize->setTickPosition(QSlider::TicksAbove);
        slider_d2BlockSize->setTickInterval(1);
        gb_district3 = new QGroupBox(frame);
        gb_district3->setObjectName(QStringLiteral("gb_district3"));
        gb_district3->setGeometry(QRect(0, 410, 200, 180));
        lbl_d3MinHeight = new QLabel(gb_district3);
        lbl_d3MinHeight->setObjectName(QStringLiteral("lbl_d3MinHeight"));
        lbl_d3MinHeight->setGeometry(QRect(20, 20, 160, 13));
        lbl_d3MaxHeight = new QLabel(gb_district3);
        lbl_d3MaxHeight->setObjectName(QStringLiteral("lbl_d3MaxHeight"));
        lbl_d3MaxHeight->setGeometry(QRect(20, 70, 160, 13));
        lbl_d3BlockSize = new QLabel(gb_district3);
        lbl_d3BlockSize->setObjectName(QStringLiteral("lbl_d3BlockSize"));
        lbl_d3BlockSize->setGeometry(QRect(20, 120, 160, 13));
        slider_d3MinHeight = new QSlider(gb_district3);
        slider_d3MinHeight->setObjectName(QStringLiteral("slider_d3MinHeight"));
        slider_d3MinHeight->setGeometry(QRect(20, 40, 160, 19));
        slider_d3MinHeight->setMinimum(1);
        slider_d3MinHeight->setMaximum(20);
        slider_d3MinHeight->setOrientation(Qt::Horizontal);
        slider_d3MinHeight->setTickPosition(QSlider::TicksAbove);
        slider_d3MinHeight->setTickInterval(1);
        slider_d3MaxHeight = new QSlider(gb_district3);
        slider_d3MaxHeight->setObjectName(QStringLiteral("slider_d3MaxHeight"));
        slider_d3MaxHeight->setGeometry(QRect(20, 90, 160, 19));
        slider_d3MaxHeight->setMinimum(1);
        slider_d3MaxHeight->setMaximum(20);
        slider_d3MaxHeight->setOrientation(Qt::Horizontal);
        slider_d3MaxHeight->setTickPosition(QSlider::TicksAbove);
        slider_d3MaxHeight->setTickInterval(1);
        slider_d3BlockSize = new QSlider(gb_district3);
        slider_d3BlockSize->setObjectName(QStringLiteral("slider_d3BlockSize"));
        slider_d3BlockSize->setGeometry(QRect(20, 140, 160, 19));
        slider_d3BlockSize->setMinimum(1);
        slider_d3BlockSize->setMaximum(20);
        slider_d3BlockSize->setOrientation(Qt::Horizontal);
        slider_d3BlockSize->setTickPosition(QSlider::TicksAbove);
        slider_d3BlockSize->setTickInterval(1);
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
        lbl_d1BlockSize->setText(QApplication::translate("MainWindow", "Block Size:", Q_NULLPTR));
        gb_district2->setTitle(QApplication::translate("MainWindow", "District 2", Q_NULLPTR));
        lbl_d2MinHeight->setText(QApplication::translate("MainWindow", "Min. Height:", Q_NULLPTR));
        lbl_d2MaxHeight->setText(QApplication::translate("MainWindow", "Max. Height:", Q_NULLPTR));
        lbl_d2BlockSize->setText(QApplication::translate("MainWindow", "Block Size:", Q_NULLPTR));
        gb_district3->setTitle(QApplication::translate("MainWindow", "District 3", Q_NULLPTR));
        lbl_d3MinHeight->setText(QApplication::translate("MainWindow", "Min. Height:", Q_NULLPTR));
        lbl_d3MaxHeight->setText(QApplication::translate("MainWindow", "Max. Height:", Q_NULLPTR));
        lbl_d3BlockSize->setText(QApplication::translate("MainWindow", "Block Size:", Q_NULLPTR));
        gb_seed->setTitle(QApplication::translate("MainWindow", "Seed", Q_NULLPTR));
        btn_generate->setText(QApplication::translate("MainWindow", "Generate", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
