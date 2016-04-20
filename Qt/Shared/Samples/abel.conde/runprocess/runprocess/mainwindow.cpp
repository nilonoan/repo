#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QProcess>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnRun, SIGNAL (released()), this, SLOT (btnRun_Clicked()));
    connect(ui->btnSave, SIGNAL (released()), this, SLOT (btnSave_Clicked()));
    connect(ui->btnClose, SIGNAL (released()), this, SLOT (btnClose_Clicked()));
    connect(ui->btnOpenDialog, SIGNAL (released()), this, SLOT (btnOpenDialog_Clicked()));
    connect(ui->btnClearPrefix, SIGNAL (released()), this, SLOT (btnClearPrefix_Clicked()));

    readConfigFile();
}

void MainWindow::readConfigFile()
{
    QFile file(QDir::currentPath() + "\\..\\runprocess\\GitHubNotify.config");
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "Error", file.errorString());
    }

    QTextStream in(&file);

    while(!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split("=");

        if (fields[0] == "[Email Subject]") {
            ui->txtCfgSubject->setText(fields[1]);
        }

        if (fields[0] == "[Send To]") {
            ui->txtCfgSendTo->setText(fields[1]);
        }

        if (fields[0] == "[Email Body]") {
            ui->txtCfgBody->setPlainText(fields[1]);
        }

        if (fields[0] == "[Data FileName]") {
            ui->txtCfgDataFile->setText(fields[1]);
        }
    }

    file.close();

    readDataFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readDataFile()
{
    QFile file(ui->txtCfgDataFile->text());
    if(!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "Error", file.errorString());
    }

    QTextStream in(&file);
    ui->txtCfgDataFileNamePreview->setPlainText(in.readAll());
    file.close();
}

void MainWindow::btnOpenDialog_Clicked()
{
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);

    QString filter = "Data files (*.data);;Any files (*.*)";
    ui->txtCfgDataFile->setText(dialog.getOpenFileName(this, "Select a file...", QDir::currentPath(), filter));

    readDataFile();
}

void MainWindow::btnClearPrefix_Clicked()
{
    QString text = ui->txtCfgDataFileNamePreview->toPlainText().replace(ui->txtPrefixPath->text(), QString(""));
    ui->txtCfgDataFileNamePreview->setPlainText(text);
}


void MainWindow::btnRun_Clicked()
{
    QProcess process;
    QString file = "wscript " + QDir::currentPath() + "\\..\\..\\runprocess\\runprocess\\GitHubNotify.vbs";
    process.start(file);
    QMessageBox::information(0, "Information", "Your notification has been sent.\nWait a moment until it reachs its destinations.");
}

void MainWindow::btnSave_Clicked()
{
    QFile file_data(ui->txtCfgDataFile->text());
    if(!file_data.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "Error", file_data.errorString());
        return;
    }

    QTextStream out_data(&file_data);

    out_data << ui->txtCfgDataFileNamePreview->toPlainText();

    file_data.close();

    QFile file(QDir::currentPath() + "\\..\\runprocess\\GitHubNotify.config");
    if(!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(0, "Error", file.errorString());
        return;
    }

    QTextStream out(&file);

    out << "[Email Subject]=" << ui->txtCfgSubject->text() << endl;
    out << "[Send To]=" << ui->txtCfgSendTo->text() << endl;
    out << "[Email Body]=" << ui->txtCfgBody->toPlainText() << endl;
    out << "[Data FileName]=" << ui->txtCfgDataFile->text() << endl;

    file.close();
    QMessageBox::information(0, "Information", "These fields were saved into config file and data file.");
}

void MainWindow::btnClose_Clicked()
{
    this->close();
}
