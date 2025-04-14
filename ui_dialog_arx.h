/********************************************************************************
** Form generated from reading UI file 'dialog_arx.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_ARX_H
#define UI_DIALOG_ARX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog_ARX
{
public:
    QVBoxLayout *verticalLayout_4;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QDoubleSpinBox *SpinBox_A1;
    QDoubleSpinBox *SpinBox_A2;
    QDoubleSpinBox *SpinBox_A3;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QDoubleSpinBox *SpinBox_B1;
    QDoubleSpinBox *SpinBox_B2;
    QDoubleSpinBox *SpinBox_B3;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QSpinBox *spinBox_k;
    QLabel *label_4;
    QDoubleSpinBox *Spbox_odchyl;
    QSpacerItem *verticalSpacer_5;
    QPushButton *buttonAccept;
    QSpacerItem *verticalSpacer_4;

    void setupUi(QDialog *Dialog_ARX)
    {
        if (Dialog_ARX->objectName().isEmpty())
            Dialog_ARX->setObjectName("Dialog_ARX");
        Dialog_ARX->resize(400, 300);
        Dialog_ARX->setBaseSize(QSize(200, 200));
        verticalLayout_4 = new QVBoxLayout(Dialog_ARX);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(Dialog_ARX);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 9);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        SpinBox_A1 = new QDoubleSpinBox(Dialog_ARX);
        SpinBox_A1->setObjectName("SpinBox_A1");
        SpinBox_A1->setMinimum(-99.000000000000000);

        horizontalLayout_2->addWidget(SpinBox_A1);

        SpinBox_A2 = new QDoubleSpinBox(Dialog_ARX);
        SpinBox_A2->setObjectName("SpinBox_A2");
        SpinBox_A2->setMinimum(-99.000000000000000);

        horizontalLayout_2->addWidget(SpinBox_A2);

        SpinBox_A3 = new QDoubleSpinBox(Dialog_ARX);
        SpinBox_A3->setObjectName("SpinBox_A3");
        SpinBox_A3->setMinimum(-99.000000000000000);

        horizontalLayout_2->addWidget(SpinBox_A3);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 2);

        verticalLayout_4->addLayout(verticalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(Dialog_ARX);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 9);

        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(20);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        SpinBox_B1 = new QDoubleSpinBox(Dialog_ARX);
        SpinBox_B1->setObjectName("SpinBox_B1");
        SpinBox_B1->setMinimum(-99.000000000000000);

        horizontalLayout_4->addWidget(SpinBox_B1);

        SpinBox_B2 = new QDoubleSpinBox(Dialog_ARX);
        SpinBox_B2->setObjectName("SpinBox_B2");
        SpinBox_B2->setMinimum(-99.000000000000000);

        horizontalLayout_4->addWidget(SpinBox_B2);

        SpinBox_B3 = new QDoubleSpinBox(Dialog_ARX);
        SpinBox_B3->setObjectName("SpinBox_B3");
        SpinBox_B3->setMinimum(-99.000000000000000);

        horizontalLayout_4->addWidget(SpinBox_B3);


        verticalLayout_2->addLayout(horizontalLayout_4);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 2);

        verticalLayout_4->addLayout(verticalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(20);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_3 = new QLabel(Dialog_ARX);
        label_3->setObjectName("label_3");

        horizontalLayout_5->addWidget(label_3);

        spinBox_k = new QSpinBox(Dialog_ARX);
        spinBox_k->setObjectName("spinBox_k");
        spinBox_k->setMinimum(1);

        horizontalLayout_5->addWidget(spinBox_k);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 3);

        horizontalLayout_6->addLayout(horizontalLayout_5);

        label_4 = new QLabel(Dialog_ARX);
        label_4->setObjectName("label_4");

        horizontalLayout_6->addWidget(label_4);

        Spbox_odchyl = new QDoubleSpinBox(Dialog_ARX);
        Spbox_odchyl->setObjectName("Spbox_odchyl");
        Spbox_odchyl->setMaximum(0.090000000000000);
        Spbox_odchyl->setSingleStep(0.010000000000000);

        horizontalLayout_6->addWidget(Spbox_odchyl);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(1, 1);
        horizontalLayout_6->setStretch(2, 2);

        verticalLayout_4->addLayout(horizontalLayout_6);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_5);

        buttonAccept = new QPushButton(Dialog_ARX);
        buttonAccept->setObjectName("buttonAccept");

        verticalLayout_4->addWidget(buttonAccept);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_4);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 2);
        verticalLayout_4->setStretch(2, 1);
        verticalLayout_4->setStretch(3, 2);
        verticalLayout_4->setStretch(4, 2);
        verticalLayout_4->setStretch(5, 2);
        verticalLayout_4->setStretch(6, 1);
        verticalLayout_4->setStretch(7, 2);
        verticalLayout_4->setStretch(8, 1);

        retranslateUi(Dialog_ARX);

        QMetaObject::connectSlotsByName(Dialog_ARX);
    } // setupUi

    void retranslateUi(QDialog *Dialog_ARX)
    {
        Dialog_ARX->setWindowTitle(QCoreApplication::translate("Dialog_ARX", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog_ARX", "A", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog_ARX", "B", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog_ARX", "K", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog_ARX", "Odchylenie", nullptr));
        buttonAccept->setText(QCoreApplication::translate("Dialog_ARX", "Akceptuj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_ARX: public Ui_Dialog_ARX {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_ARX_H
