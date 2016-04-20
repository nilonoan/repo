#include "validationform.h"
#include "ui_validationform.h"

#include <QString>
#include <QDateTime>
#include <QTime>

ValidationForm::ValidationForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ValidationForm)
{
    ui->setupUi(this);

    connect(ui->optNum, SIGNAL (released()), this, SLOT (optNum_Clicked()));
    connect(ui->optDate, SIGNAL (released()), this, SLOT (optDate_Clicked()));

    connect(ui->optSum, SIGNAL (released()), this, SLOT (optSum_Clicked()));
    connect(ui->optMinus, SIGNAL (released()), this, SLOT (optMinus_Clicked()));
    connect(ui->optMulti, SIGNAL (released()), this, SLOT (optMulti_Clicked()));
    connect(ui->optDiv, SIGNAL (released()), this, SLOT (optDiv_Clicked()));

    connect(ui->btnCalculate, SIGNAL (released()), this, SLOT (btnCalculate_Clicked()));
    connect(ui->btnClose, SIGNAL (released()), this, SLOT (btnClose_Clicked())); 

    ui->optNum->setChecked(true);
    ui->optSum->setChecked(true);

    ui->lblHelpDtFormat->setVisible(false);
    ui->lblHelpDayFormat->setVisible(false);
}

ValidationForm::~ValidationForm()
{
    delete ui;
}

void ValidationForm::clearFields()
{
    ui->txtDataA->setText("");
    ui->txtDataB->setText("");
    ui->txtDataTotal->setText("");
}

void ValidationForm::optNum_Clicked()
{
    ui->optMulti->setEnabled(true);
    ui->optDiv->setEnabled(true);
    ui->lblHelpDtFormat->setVisible(false);
    ui->lblHelpDayFormat->setVisible(false);
    clearFields();
    e_datatype = NUMBER;
}

void ValidationForm::optDate_Clicked()
{
    ui->optMulti->setEnabled(false);
    ui->optDiv->setEnabled(false);
    ui->lblHelpDtFormat->setVisible(true);
    ui->lblHelpDayFormat->setVisible(true);
    clearFields();
    e_datatype = DATE;
}

void ValidationForm::optSum_Clicked()
{
    ui->lblOperator->setText("+");
    ui->txtDataTotal->setText("");
    e_operationtype = SUM;
}

void ValidationForm::optMinus_Clicked()
{
    ui->lblOperator->setText("-");
    ui->txtDataTotal->setText("");
    e_operationtype = MINUS;
}

void ValidationForm::optMulti_Clicked()
{
    ui->lblOperator->setText("*");
    ui->txtDataTotal->setText("");
    e_operationtype = MULTIPLY;
}

void ValidationForm::optDiv_Clicked()
{
    ui->lblOperator->setText("÷");
    ui->txtDataTotal->setText("");
    e_operationtype = DIVIDE;
}

void ValidationForm::btnCalculate_Clicked()
{
    if (e_datatype == NUMBER)
    {
        float fA = ui->txtDataA->text().toFloat();
        float fB = ui->txtDataB->text().toFloat();

        if (e_operationtype == SUM)
            ui->txtDataTotal->setText(QString::number(fA + fB));
        else if (e_operationtype == MINUS)
            ui->txtDataTotal->setText(QString::number(fA - fB));
        else if (e_operationtype == MULTIPLY)
            ui->txtDataTotal->setText(QString::number(fA * fB));
        else if (e_operationtype == DIVIDE)
            ui->txtDataTotal->setText(QString::number(fA / fB));
    }

    if (e_datatype == DATE)
    {
        QDateTime dtA = QDateTime::fromString(ui->txtDataA->text(), "dd/MM/yyyy");
        int days = ui->txtDataB->text().toInt();

        if (e_operationtype == SUM)
            ui->txtDataTotal->setText(dtA.addDays(days).toString("dd/MM/yyyy"));
        else if (e_operationtype == MINUS)
            ui->txtDataTotal->setText(dtA.addDays(days * (-1)).toString("dd/MM/yyyy"));
    }
}

void ValidationForm::btnClose_Clicked()
{
    close();
}

