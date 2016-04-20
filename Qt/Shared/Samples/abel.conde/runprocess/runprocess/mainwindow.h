#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void btnOpenDialog_Clicked();
    void btnRun_Clicked();
    void btnSave_Clicked();
    void btnClose_Clicked();
    void btnClearPrefix_Clicked();

private:
    void readConfigFile();
    void readDataFile();

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
