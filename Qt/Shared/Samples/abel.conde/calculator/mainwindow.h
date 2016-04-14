#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "validationform.h"

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
    void btnOpen_Clicked();

private:
    Ui::MainWindow *ui;
    ValidationForm *ValForm;
};

#endif // MAINWINDOW_H
