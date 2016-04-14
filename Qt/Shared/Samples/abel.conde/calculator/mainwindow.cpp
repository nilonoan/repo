#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnOpen, SIGNAL (released()), this, SLOT (btnOpen_Clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::btnOpen_Clicked()
{
    ValForm = new ValidationForm;
    ValForm->show();
}
