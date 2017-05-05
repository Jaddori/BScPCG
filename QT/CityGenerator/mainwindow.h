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

private:
    Ui::MainWindow *ui;
    SeedConverter seedConverter;
};

#endif // MAINWINDOW_H
