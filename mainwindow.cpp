#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),timer(new QTimer(this))
{
    ui->setupUi(this);
    sym.Setup();
    connect(timer,SIGNAL(timeout()),this,SLOT(advance()));
    on_Spbox_inter_valueChanged(ui->Spbox_inter->value());
    on_Spbox_Stala_valueChanged(ui->ustaw_S->value());
    on_ustawA_valueChanged(ui->ustawA->value());
    on_ustawP_valueChanged(ui->ustawP->value());
    on_ustawT_valueChanged(ui->ustawT->value());
    on_ustawKpid_valueChanged(ui->ustawKpid->value());
    on_ustawTi_valueChanged(ui->ustawTi->value());
    on_ustawTd_valueChanged(ui->ustawTd->value());
    sym.set_a1(-0.4);
    sym.set_a2(0.2);
    sym.set_a3(0.0);
    sym.set_b1(0.6);
    sym.set_b2(0.3);
    sym.set_b3(0.0);
    sym.set_arx_k(1);
    sig();
    edit_ARX = new Dialog_ARX;
    connect(edit_ARX,SIGNAL(accepted()),this,SLOT(Pobiezdane_ARX()));
    ustawNazwy();
    dodajSerie();
    utworzOsie();
    ui->ChartUchyb->setChart(chart1);
    ui->Chartwartosci->setChart(chart2);
    ui->ChartSterowanie->setChart(chart3);
    serwer = new QTcpServer(this);
    gniazdoKlienta = new QTcpSocket(this);
    connect(serwer, &QTcpServer::newConnection, this, [=]() {
        QTcpSocket* polaczenie = serwer->nextPendingConnection();
        ui->labelStatus->setText("Połączono jako serwer");
    });
    connect(gniazdoKlienta, &QTcpSocket::connected, this, [=]() {
        ui->labelStatus->setText("Połączono jako klient");
    });
    connect(gniazdoKlienta, &QTcpSocket::disconnected, this, [=]() {
        ui->labelStatus->setText("Rozłączono z serwerem");
    });
}

MainWindow::~MainWindow()
{
    delete ui;
    delete edit_ARX;
    usunSerie();
    usun_charty();
}

void MainWindow::sig()
{
    signal newsig;
    string text=ui->Sygnal->currentText().toStdString();
    if(text=="Pros")newsig=signal::syg_prost;
    else if(text=="Sinusoida")newsig=signal::syg_sin;
    else newsig=signal::sk_jed;
    sym.set_syg(newsig);
}

void MainWindow::advance()
{
    if(sym.get_start()){
        sym.symulacja();
        if(sym.get_ite()>42.0)
        {
            x=(sym.get_ite()-38.0);
            series->remove(0);
            series2->remove(0);
            series3->remove(0);
            series4->remove(0);
            series5->remove(0);
            series6->remove(0);
            series7->remove(0);
        }
        dodacDoSerii();
        resetMaksMin();
        ustawMin();
        ustawMax();
        ustawZakres();
    }

}

void MainWindow::on_ustawA_valueChanged(double arg1)
{
    sym.set_zad(arg1);
}

void MainWindow::on_ustawP_valueChanged(double arg1)
{
    sym.set_p(arg1);
}

void MainWindow::on_ustawT_valueChanged(int arg1)
{
    sym.set_T(arg1);
}

void MainWindow::on_ustawKpid_valueChanged(double arg1)
{
    sym.set_pid_k(arg1);
}

void MainWindow::on_ustawTi_valueChanged(double arg1)
{
    sym.set_pid_Ti(arg1);
}

void MainWindow::on_ustawTd_valueChanged(double arg1)
{
    sym.set_pid_Td(arg1);
}

void MainWindow::dodajSerie()
{
    chart1->addSeries(series);
    chart2->addSeries(series2);
    chart2->addSeries(series3);
    chart3->addSeries(series4);
    chart3->addSeries(series5);
    chart3->addSeries(series6);
    chart3->addSeries(series7);
}

void MainWindow::usunSerie()
{
    delete series;
    delete series2;
    delete series3;
    delete series4;
    delete series5;
    delete series6;
    delete series7;
}

void MainWindow::utworzSerie()
{
    series = new QLineSeries();
    series2 = new QLineSeries();
    series3 = new QLineSeries();
    series4 = new QLineSeries();
    series5 = new QLineSeries();
    series6 = new QLineSeries();
    series7 = new QLineSeries();
}

void MainWindow::resetMaksMin()
{
    maks_y1=0.00001;
    maks_y2=0.00001;
    maks_y3=0.00001;
    min_y1=-0.00001;
    min_y2=-0.00001;
    min_y3=-0.00001;
}

void MainWindow::utworzOsie()
{
    chart1->createDefaultAxes();
    chart2->createDefaultAxes();
    chart3->createDefaultAxes();

    chart1->axes(Qt::Horizontal).first()->setTitleText("iteracja");
    chart1->axes(Qt::Vertical).first()->setTitleText("Odp");
    chart2->axes(Qt::Horizontal).first()->setTitleText("iteracja");
    chart2->axes(Qt::Vertical).first()->setTitleText("Odp");
    chart3->axes(Qt::Horizontal).first()->setTitleText("iteracja");
    chart3->axes(Qt::Vertical).first()->setTitleText("Odp");
}

void MainWindow::ustawNazwy()
{
    series->setName("Uchyb");
    series2->setName("Zadana");
    series3->setName("Regulowana");
    series4->setName("P");
    series5->setName("I");
    series6->setName("D");
    series7->setName("sterowanie");


}

void MainWindow::ustawZakres()
{
    chart1->axes(Qt::Horizontal).first()->setRange(x,sym.get_ite());
    chart1->axes(Qt::Vertical).first()->setRange(min_y1-abs(0.2*min_y1),maks_y1*1.5);
    chart2->axes(Qt::Vertical).first()->setRange(min_y2-abs(0.2*min_y2),maks_y2*1.5);
    chart2->axes(Qt::Horizontal).first()->setRange(x,sym.get_ite());
    chart3->axes(Qt::Horizontal).first()->setRange(x,sym.get_ite());
    chart3->axes(Qt::Vertical).first()->setRange(min_y3 - abs(0.2*min_y3),maks_y3*1.5);
}

void MainWindow::dodacDoSerii()
{
    series->append(sym.get_ite(),sym.get_u());
    series2->append(sym.get_ite(),sym.get_Zad());
    series3->append(sym.get_ite(),sym.get_Y());
    series4->append(sym.get_ite(),sym.get_P());
    series5->append(sym.get_ite(),sym.get_I());
    series6->append(sym.get_ite(),sym.get_D());
    series7->append(sym.get_ite(),sym.get_ster());
}

void MainWindow::ustawMin()
{
    if(min_y1<0.0001 && min_y1>-0.0001)
        min_y1=-0.0001;
    ZakresWykresu(min_y1,series);
    ZakresWykresu(min_y2,series2);
    ZakresWykresu(min_y2,series3);
    ZakresWykresu(min_y3,series4);
    ZakresWykresu(min_y3,series5);
    ZakresWykresu(min_y3,series6);
    ZakresWykresu(min_y3,series7);
}

void MainWindow::ustawMax()
{
    if(maks_y1<0.0001 && maks_y1>-0.0001)
    maks_y1=0.0001;
    ZakresWykresu(maks_y1,series,false);
    ZakresWykresu(maks_y2,series2,false);
    ZakresWykresu(maks_y2,series3,false);
    ZakresWykresu(maks_y3,series4,false);
    ZakresWykresu(maks_y3,series5,false);
    ZakresWykresu(maks_y3,series6,false);
    ZakresWykresu(maks_y3,series7,false);
}

void MainWindow::ZakresWykresu(double &y, QLineSeries * &seria, bool czy_min)
{
    int j=min(38,sym.get_ite());
    if(czy_min)
    {
        for(int i = 0; i<j; i++)
        {y=min(seria->at(i).y(),y);}
    }
    else
    {
        for(int i = 0; i<j; i++)
        {y=max(seria->at(i).y(),y);}
    }
}

void MainWindow:: usun_charty()
{
    delete chart1;
    delete chart2;
    delete chart3;
}

void MainWindow::on_Spbox_inter_valueChanged(double arg1)
{
    timer->setInterval(arg1*1000);
}

void MainWindow::Pobiezdane_ARX()
{

    sym.set_a1(edit_ARX->a1);
    sym.set_a2(edit_ARX->a2);
    sym.set_a3(edit_ARX->a3);
    sym.set_b1(edit_ARX->b1);
    sym.set_b2(edit_ARX->b2);
    sym.set_b3(edit_ARX->b3);
    sym.set_arx_k(edit_ARX->K);
    sym.Set_Odch(edit_ARX->odchyl);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    sym.set_tryb(ui->chboxCalka->isChecked());
}

void MainWindow::on_Spbox_Stala_valueChanged(double arg1)
{
    sym.set_stala(arg1);
}

void MainWindow::on_StartStop_clicked()
{
    sym.StartStop();
    working=!working;
    if(!working)timer->stop();else timer->start();
}

void MainWindow::on_Reset_clicked()
{
    if(working)on_StartStop_clicked();
    if(!working)timer->stop();
    sym.Setup();
    sym.reset();
    x=0;
    usunSerie();

    utworzSerie();

    ustawNazwy();

    resetMaksMin();

    dodajSerie();

    utworzOsie();


    ui->ChartUchyb->setChart(chart1);
    ui->Chartwartosci->setChart(chart2);
    ui->ChartSterowanie->setChart(chart3);
}

void MainWindow::on_ustaw_S_valueChanged(double arg1)
{
    sym.set_stala(arg1);
}

void MainWindow::on_Sygnal_currentTextChanged(const QString &arg1)
{
    Q_UNUSED(arg1);
    sig();
}

void MainWindow::on_chboxCalka_stateChanged(int arg1)
{
    sym.set_tryb(ui->chboxCalka->isChecked());
}

void MainWindow::on_pidReset_clicked()
{
    sym.reset();
}

void MainWindow::on_edytujARX_clicked()
{
    edit_ARX->Set_A1(sym.Get_A_ARX(0));
    edit_ARX->Set_A2(sym.Get_A_ARX(1));
    edit_ARX->Set_A3(sym.Get_A_ARX(2));
    edit_ARX->Set_B1(sym.Get_B_ARX(0));
    edit_ARX->Set_B2(sym.Get_B_ARX(1));
    edit_ARX->Set_B3(sym.Get_B_ARX(2));
    edit_ARX->Set_K(sym.Get_K_ARX());
    edit_ARX->Set_Odchyl(sym.Get_odchyl_Arx());
    edit_ARX->show();
}

void MainWindow::on_checkSiec_stateChanged(int stan)
{
    trybSiec = (stan == Qt::Checked);
    if (trybSiec)
    {
        serwer->listen(QHostAddress::Any, 12345);
    }
    if (!trybSiec) {
        serwer->close();
        gniazdoKlienta->disconnectFromHost();
        ui->labelStatus->clear();
    }
    ui->ustawA->setEnabled(!trybSiec);
    ui->ustawP->setEnabled(!trybSiec);
    ui->ustawT->setEnabled(!trybSiec);
    ui->Sygnal->setEnabled(!trybSiec);
    ui->ustawKpid->setEnabled(!trybSiec);
    ui->ustawTi->setEnabled(!trybSiec);
    ui->ustawTd->setEnabled(!trybSiec);
    ui->ustaw_S->setEnabled(!trybSiec);
    ui->Spbox_inter->setEnabled(!trybSiec);
    ui->pidReset->setEnabled(!trybSiec);
    ui->edytujARX->setEnabled(!trybSiec);
}

void MainWindow::on_btnPolacz_clicked()
{
    if (trybSiec) {
        QString ip = ui->lineIP->text();
        if (gniazdoKlienta->state() != QAbstractSocket::UnconnectedState) {
            gniazdoKlienta->abort();
        }
        gniazdoKlienta->connectToHost(ip, 12345);
    }
}


