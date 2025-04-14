/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_15;
    QVBoxLayout *verticalLayout_16;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *StartStop;
    QPushButton *Reset;
    QDoubleSpinBox *Spbox_inter;
    QLabel *label_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_12;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_12;
    QDoubleSpinBox *ustaw_S;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_5;
    QSpinBox *ustawT;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_6;
    QComboBox *Sygnal;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_3;
    QDoubleSpinBox *ustawA;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_4;
    QDoubleSpinBox *ustawP;
    QFrame *frame_2;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_10;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_11;
    QDoubleSpinBox *ustawKpid;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_7;
    QDoubleSpinBox *ustawTd;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_8;
    QCheckBox *chboxCalka;
    QDoubleSpinBox *ustawTi;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_9;
    QPushButton *pidReset;
    QFrame *frame_3;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout_14;
    QLabel *label_14;
    QPushButton *edytujARX;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *checkSiec;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_13;
    QLineEdit *lineIP;
    QPushButton *btnPolacz;
    QLabel *labelStatus;
    QVBoxLayout *verticalLayout;
    QChartView *Chartwartosci;
    QHBoxLayout *horizontalLayout_3;
    QChartView *ChartUchyb;
    QChartView *ChartSterowanie;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1189, 673);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName("formLayout");
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setSpacing(3);
        verticalLayout_15->setObjectName("verticalLayout_15");
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName("verticalLayout_16");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(4);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        StartStop = new QPushButton(centralwidget);
        StartStop->setObjectName("StartStop");

        horizontalLayout_8->addWidget(StartStop);

        Reset = new QPushButton(centralwidget);
        Reset->setObjectName("Reset");

        horizontalLayout_8->addWidget(Reset);

        Spbox_inter = new QDoubleSpinBox(centralwidget);
        Spbox_inter->setObjectName("Spbox_inter");
        Spbox_inter->setMinimum(0.050000000000000);
        Spbox_inter->setSingleStep(0.050000000000000);
        Spbox_inter->setValue(0.100000000000000);

        horizontalLayout_8->addWidget(Spbox_inter);


        verticalLayout_16->addLayout(horizontalLayout_8);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        verticalLayout_16->addWidget(label_2);


        verticalLayout_15->addLayout(verticalLayout_16);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::Box);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame);
        horizontalLayout_7->setSpacing(3);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(3, 3, 3, 3);
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName("verticalLayout_12");
        label = new QLabel(frame);
        label->setObjectName("label");

        verticalLayout_12->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_12 = new QLabel(frame);
        label_12->setObjectName("label_12");
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_2->addWidget(label_12);

        ustaw_S = new QDoubleSpinBox(frame);
        ustaw_S->setObjectName("ustaw_S");
        ustaw_S->setMinimum(-100.000000000000000);
        ustaw_S->setSingleStep(0.100000000000000);
        ustaw_S->setValue(1.000000000000000);

        horizontalLayout_2->addWidget(ustaw_S);


        verticalLayout_12->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(9);
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_9->addWidget(label_5);

        ustawT = new QSpinBox(frame);
        ustawT->setObjectName("ustawT");
        ustawT->setMinimum(1);
        ustawT->setValue(1);

        verticalLayout_9->addWidget(ustawT);


        gridLayout->addLayout(verticalLayout_9, 1, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_6 = new QLabel(frame);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_8->addWidget(label_6);

        Sygnal = new QComboBox(frame);
        Sygnal->addItem(QString());
        Sygnal->addItem(QString());
        Sygnal->addItem(QString());
        Sygnal->setObjectName("Sygnal");

        verticalLayout_8->addWidget(Sygnal);


        gridLayout->addLayout(verticalLayout_8, 1, 1, 1, 1);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_11->addWidget(label_3);

        ustawA = new QDoubleSpinBox(frame);
        ustawA->setObjectName("ustawA");
        ustawA->setDecimals(3);
        ustawA->setMinimum(-99.000000000000000);
        ustawA->setSingleStep(0.500000000000000);
        ustawA->setValue(1.000000000000000);

        verticalLayout_11->addWidget(ustawA);


        gridLayout->addLayout(verticalLayout_11, 0, 0, 1, 1);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_10->addWidget(label_4);

        ustawP = new QDoubleSpinBox(frame);
        ustawP->setObjectName("ustawP");
        ustawP->setMaximum(1.000000000000000);
        ustawP->setSingleStep(0.100000000000000);
        ustawP->setValue(0.500000000000000);

        verticalLayout_10->addWidget(ustawP);


        gridLayout->addLayout(verticalLayout_10, 0, 1, 1, 1);


        verticalLayout_12->addLayout(gridLayout);

        verticalLayout_12->setStretch(0, 1);
        verticalLayout_12->setStretch(1, 2);
        verticalLayout_12->setStretch(2, 4);

        horizontalLayout_7->addLayout(verticalLayout_12);


        verticalLayout_15->addWidget(frame);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::Box);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_3 = new QGridLayout(frame_2);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        label_10 = new QLabel(frame_2);
        label_10->setObjectName("label_10");

        verticalLayout_13->addWidget(label_10);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(4);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_11 = new QLabel(frame_2);
        label_11->setObjectName("label_11");
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_7->addWidget(label_11);

        ustawKpid = new QDoubleSpinBox(frame_2);
        ustawKpid->setObjectName("ustawKpid");
        ustawKpid->setSingleStep(0.500000000000000);
        ustawKpid->setValue(0.500000000000000);

        verticalLayout_7->addWidget(ustawKpid);


        gridLayout_2->addLayout(verticalLayout_7, 0, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(4);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_7 = new QLabel(frame_2);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_6->addWidget(label_7);

        ustawTd = new QDoubleSpinBox(frame_2);
        ustawTd->setObjectName("ustawTd");
        ustawTd->setSingleStep(0.500000000000000);
        ustawTd->setValue(0.200000000000000);

        verticalLayout_6->addWidget(ustawTd);


        gridLayout_2->addLayout(verticalLayout_6, 1, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_8 = new QLabel(frame_2);
        label_8->setObjectName("label_8");
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(label_8);

        chboxCalka = new QCheckBox(frame_2);
        chboxCalka->setObjectName("chboxCalka");
        chboxCalka->setChecked(true);

        verticalLayout_5->addWidget(chboxCalka);

        ustawTi = new QDoubleSpinBox(frame_2);
        ustawTi->setObjectName("ustawTi");
        ustawTi->setSingleStep(0.500000000000000);
        ustawTi->setValue(5.000000000000000);

        verticalLayout_5->addWidget(ustawTi);


        gridLayout_2->addLayout(verticalLayout_5, 0, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(4);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_9 = new QLabel(frame_2);
        label_9->setObjectName("label_9");
        label_9->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(label_9);

        pidReset = new QPushButton(frame_2);
        pidReset->setObjectName("pidReset");

        verticalLayout_4->addWidget(pidReset);


        gridLayout_2->addLayout(verticalLayout_4, 1, 1, 1, 1);


        verticalLayout_13->addLayout(gridLayout_2);

        verticalLayout_13->setStretch(1, 4);

        gridLayout_3->addLayout(verticalLayout_13, 0, 0, 1, 1);


        verticalLayout_15->addWidget(frame_2);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::Box);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_4 = new QGridLayout(frame_3);
        gridLayout_4->setObjectName("gridLayout_4");
        gridLayout_4->setContentsMargins(3, 3, 3, 3);
        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName("verticalLayout_14");
        label_14 = new QLabel(frame_3);
        label_14->setObjectName("label_14");
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_14->addWidget(label_14);

        edytujARX = new QPushButton(frame_3);
        edytujARX->setObjectName("edytujARX");

        verticalLayout_14->addWidget(edytujARX);

        verticalLayout_14->setStretch(0, 1);
        verticalLayout_14->setStretch(1, 2);

        gridLayout_4->addLayout(verticalLayout_14, 0, 0, 1, 1);


        verticalLayout_15->addWidget(frame_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");

        verticalLayout_15->addLayout(verticalLayout_2);

        checkSiec = new QCheckBox(centralwidget);
        checkSiec->setObjectName("checkSiec");

        verticalLayout_15->addWidget(checkSiec);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName("label_13");

        horizontalLayout_4->addWidget(label_13);

        lineIP = new QLineEdit(centralwidget);
        lineIP->setObjectName("lineIP");
        lineIP->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_4->addWidget(lineIP);


        verticalLayout_15->addLayout(horizontalLayout_4);

        btnPolacz = new QPushButton(centralwidget);
        btnPolacz->setObjectName("btnPolacz");

        verticalLayout_15->addWidget(btnPolacz);

        labelStatus = new QLabel(centralwidget);
        labelStatus->setObjectName("labelStatus");

        verticalLayout_15->addWidget(labelStatus);

        verticalLayout_15->setStretch(0, 1);
        verticalLayout_15->setStretch(1, 3);
        verticalLayout_15->setStretch(2, 3);
        verticalLayout_15->setStretch(3, 2);

        formLayout->setLayout(0, QFormLayout::LabelRole, verticalLayout_15);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(2);
        verticalLayout->setObjectName("verticalLayout");
        Chartwartosci = new QChartView(centralwidget);
        Chartwartosci->setObjectName("Chartwartosci");

        verticalLayout->addWidget(Chartwartosci);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        ChartUchyb = new QChartView(centralwidget);
        ChartUchyb->setObjectName("ChartUchyb");

        horizontalLayout_3->addWidget(ChartUchyb);

        ChartSterowanie = new QChartView(centralwidget);
        ChartSterowanie->setObjectName("ChartSterowanie");

        horizontalLayout_3->addWidget(ChartSterowanie);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 2);

        formLayout->setLayout(0, QFormLayout::FieldRole, verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1189, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SUAR", nullptr));
        StartStop->setText(QCoreApplication::translate("MainWindow", "Start/Stop", nullptr));
        Reset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Interwa\305\202", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Generator", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "S", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "T", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Sygna\305\202", nullptr));
        Sygnal->setItemText(0, QCoreApplication::translate("MainWindow", "Skok", nullptr));
        Sygnal->setItemText(1, QCoreApplication::translate("MainWindow", "Pros", nullptr));
        Sygnal->setItemText(2, QCoreApplication::translate("MainWindow", "Sinusoida", nullptr));

        label_3->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "P", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "PID", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "K", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Td", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Ti", nullptr));
        chboxCalka->setText(QCoreApplication::translate("MainWindow", "Przed sum\304\205", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Pami\304\231\304\207", nullptr));
        pidReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "ARX", nullptr));
        edytujARX->setText(QCoreApplication::translate("MainWindow", "Modyfikuj", nullptr));
        checkSiec->setText(QCoreApplication::translate("MainWindow", "Tryb sieciowy", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Adres: ", nullptr));
        lineIP->setText(QCoreApplication::translate("MainWindow", "127.0.01", nullptr));
        btnPolacz->setText(QCoreApplication::translate("MainWindow", "Po\305\202\304\205cz", nullptr));
        labelStatus->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
