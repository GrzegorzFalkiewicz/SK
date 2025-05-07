#include "dialog_arx.h"
#include "ui_dialog_arx.h"

Dialog_ARX::Dialog_ARX(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_ARX)
{
    ui->setupUi(this);
}

Dialog_ARX::~Dialog_ARX()
{
    delete ui;
}


void Dialog_ARX::Set_A1(double a)
{
    ui->SpinBox_A1->setValue(a);
}

void Dialog_ARX::Set_A2(double a)
{
    ui->SpinBox_A2->setValue(a);
}

void Dialog_ARX::Set_A3(double a)
{
    ui->SpinBox_A3->setValue(a);
}

void Dialog_ARX::Set_B1(double a)
{
    ui->SpinBox_B1->setValue(a);
}

void Dialog_ARX::Set_B2(double a)
{
    ui->SpinBox_B2->setValue(a);
}

void Dialog_ARX::Set_B3(double a)
{
    ui->SpinBox_B3->setValue(a);
}


void Dialog_ARX::Set_K(int k)
{
    ui->spinBox_k->setValue(k);
}

void Dialog_ARX::Set_Odchyl(double a)
{
    ui->Spbox_odchyl->setValue(a);


}


void Dialog_ARX::on_buttonAccept_clicked()
{
    //wyciągniecie wartości do pól po zaakceptowaniu zmian
    a1=ui->SpinBox_A1->value();
    a2=ui->SpinBox_A2->value();
    a3=ui->SpinBox_A3->value();
    b1=ui->SpinBox_B1->value();
    b2=ui->SpinBox_B2->value();
    b3=ui->SpinBox_B3->value();
    K=ui->spinBox_k->value();
    odchyl=ui->Spbox_odchyl->value();
    // emisja sygnału połączonego ze slotem w okienku głównym
    emit accept();
}

