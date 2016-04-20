#ifndef VALIDATIONFORM_H
#define VALIDATIONFORM_H

#include <QWidget>

namespace Ui {
    class ValidationForm;
}

class ValidationForm : public QWidget
{
    Q_OBJECT

public:
    explicit ValidationForm(QWidget *parent = 0);
    ~ValidationForm();

private slots:
    void optNum_Clicked();
    void optDate_Clicked();
    void optSum_Clicked();
    void optMinus_Clicked();
    void optMulti_Clicked();
    void optDiv_Clicked();
    void btnCalculate_Clicked();
    void btnClose_Clicked();

private:
    void clearFields();

    typedef enum {NUMBER, DATE} data_type;
    typedef enum {SUM, MINUS, MULTIPLY, DIVIDE} operation_type;

    data_type e_datatype = NUMBER;
    operation_type e_operationtype = SUM;

    Ui::ValidationForm *ui;
};

#endif // VALIDATIONFORM_H

