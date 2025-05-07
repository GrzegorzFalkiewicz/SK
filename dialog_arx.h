#ifndef DIALOG_ARX_H
#define DIALOG_ARX_H

#include <QDialog>

namespace Ui {
class Dialog_ARX;
}

class Dialog_ARX : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_ARX(QWidget *parent = nullptr);
    ~Dialog_ARX();

    //publiczne pola do przechowywania danych przekazywanych symulatorowi
    double a1;
    double a2;
    double a3;
    double b1;
    double b2;
    double b3;
    double odchyl;
    int K;

    //setery wartości w kontrolkach
    void    Set_A1(double a);
    void    Set_A2(double a);
    void    Set_A3(double a);
    void    Set_B1(double a);
    void    Set_B2(double a);
    void    Set_B3(double a);
    void    Set_Odchyl(double a);
    void    Set_K(int k);
private slots:

    void on_buttonAccept_clicked();

private:
    Ui::Dialog_ARX *ui;

};

#endif // DIALOG_ARX_H
