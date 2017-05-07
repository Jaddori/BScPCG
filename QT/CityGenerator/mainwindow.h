#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Elicras.h"
#include "SeedConverter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_btn_generate_clicked();

    void on_slider_d1MinHeight_valueChanged(int value);

    void on_slider_d2MinHeight_valueChanged(int value);

    void on_slider_d3MinHeight_valueChanged(int value);

    void on_slider_d1MaxHeight_valueChanged(int value);

    void on_slider_d2MaxHeight_valueChanged(int value);

    void on_slider_d3MaxHeight_valueChanged(int value);

    void on_slider_d1Density_valueChanged(int value);

    void on_slider_d2Density_valueChanged(int value);

    void on_slider_d3Density_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    SeedConverter seedConverter;
};

#endif // MAINWINDOW_H
