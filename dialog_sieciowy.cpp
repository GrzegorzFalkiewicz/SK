#include "dialog_sieciowy.h"
#include "ui_dialog_sieciowy.h"

dialog_sieciowy::dialog_sieciowy(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialog_sieciowy)
    , serwer(new QTcpServer(this))
    , klient(new QTcpSocket(this))
    , polaczoneGniazdo(nullptr)
    , migacz(new QTimer(this))
    , reconnector(new QTimer(this))
{
    ui->setupUi(this);
    trybSieciowyWlaczony = false;
    ustawKontrolke("gray");
    ui->groupTryb->hide();
    pokazElementySerwera(false);
    pokazElementyKlienta(false);
    rozlaczonoRecznie = false;

    connect(serwer, &QTcpServer::newConnection, this, &dialog_sieciowy::nowyKlient);
    connect(klient, &QTcpSocket::connected, this, &dialog_sieciowy::polaczonoZSerwerem);
    connect(klient, &QTcpSocket::disconnected, this, &dialog_sieciowy::rozlaczonoZSerwerem);
    connect(klient, &QTcpSocket::errorOccurred, this, &dialog_sieciowy::bladPolaczenia);
    connect(migacz, &QTimer::timeout, this, &dialog_sieciowy::resetujKontrolke);

    reconnector->setInterval(3000); // próba co 3 sekundy
    connect(reconnector, &QTimer::timeout, this, [=]() {
        if (trybSieciowyWlaczony && ui->radioKlient->isChecked() && klient->state() == QAbstractSocket::UnconnectedState) {
            QString ip = ui->lineIP->text();
            quint16 port = ui->linePortKlient->text().toUShort();
            klient->connectToHost(ip, port);
            ustawKontrolke("orange");
            wyswietlKomunikat("Ponawianie połączenia z serwerem...");
        }
    });
}

dialog_sieciowy::~dialog_sieciowy()
{
    delete ui;
}

void dialog_sieciowy::on_btnWlaczSiec_clicked()
{
    if (!trybSieciowyWlaczony) {
        trybSieciowyWlaczony = true;
        ui->btnWlaczSiec->setText("Wyłącz sieć");
        ui->groupTryb->show();
        ustawKontrolke("orange");
        wyswietlKomunikat("Sieć włączona. Wybierz tryb.");
    } else {
        trybSieciowyWlaczony = false;
        ui->btnWlaczSiec->setText("Włącz sieć");
        ui->groupTryb->hide();
        pokazElementySerwera(false);
        pokazElementyKlienta(false);
        ustawKontrolke("gray");
        wyswietlKomunikat("Tryb sieciowy wyłączony.");

        // Rozłączenie wszystkiego
        if (serwer->isListening()) {
            serwer->close();
        }
        if (polaczoneGniazdo && polaczoneGniazdo->isOpen()) {
            polaczoneGniazdo->disconnectFromHost();
        }
        if (klient->isOpen()) {
            klient->disconnectFromHost();
        }

        ui->radioSerwer->setEnabled(true);
        ui->radioKlient->setEnabled(true);
    }
}

void dialog_sieciowy::on_radioSerwer_toggled(bool checked)
{
    if (checked) {
        pokazElementySerwera(true);
        pokazElementyKlienta(false);
        wyswietlKomunikat("Wybrano tryb: Serwer");
    }
}

void dialog_sieciowy::on_radioKlient_toggled(bool checked)
{
    if (checked) {
        pokazElementySerwera(false);
        pokazElementyKlienta(true);
        wyswietlKomunikat("Wybrano tryb: Klient");
    }
}

void dialog_sieciowy::on_btnStartSerwer_clicked()
{
    ui->btnStartSerwer->setEnabled(false);
    ui->radioSerwer->setEnabled(false);
    ui->radioKlient->setEnabled(false);
    quint16 port = ui->linePortSerwer->text().toUShort();
    if (!serwer->listen(QHostAddress::Any, port)) {
        ustawKontrolke("red");
        wyswietlKomunikat("Błąd: nie można uruchomić serwera.");
    } else {
        ustawKontrolke("green");
        wyswietlKomunikat("Serwer nasłuchuje na porcie " + QString::number(port));
    }
}

void dialog_sieciowy::nowyKlient()
{
    polaczoneGniazdo = serwer->nextPendingConnection();
    QString ip = polaczoneGniazdo->peerAddress().toString();
    if (ip.startsWith("::ffff:")) ip = ip.mid(7);
    wyswietlKomunikat("Klient połączony. Adres: " + ip);
    migajKontrolka("green", "gray");

    connect(polaczoneGniazdo, &QTcpSocket::disconnected, this, &dialog_sieciowy::klientRozlaczyl);
}

void dialog_sieciowy::klientRozlaczyl()
{
    wyswietlKomunikat("Klient został rozłączony.");
    ustawKontrolke("orange");
    QTimer::singleShot(600, this, [=]() { ustawKontrolke("green"); });
}

void dialog_sieciowy::on_btnStopSerwer_clicked()
{
    ui->btnStartSerwer->setEnabled(true);
    ui->radioSerwer->setEnabled(true);
    ui->radioKlient->setEnabled(true);
    if (serwer->isListening()) {
        serwer->close();
        ustawKontrolke("orange");
        wyswietlKomunikat("Serwer został wyłączony.");
    }
    if (polaczoneGniazdo && polaczoneGniazdo->state() == QAbstractSocket::ConnectedState) {
        polaczoneGniazdo->disconnectFromHost();
    }
}

void dialog_sieciowy::on_btnPolaczKlient_clicked()
{
    ui->btnPolaczKlient->setEnabled(false);
    ui->radioSerwer->setEnabled(false);
    ui->radioKlient->setEnabled(false);
    QString ip = ui->lineIP->text();
    quint16 port = ui->linePortKlient->text().toUShort();
    klient->connectToHost(ip, port);
    ustawKontrolke("orange");
    wyswietlKomunikat("Łączenie z serwerem...");
    reconnector->start();
}

void dialog_sieciowy::polaczonoZSerwerem()
{
    reconnector->stop();
    ui->radioSerwer->setEnabled(false);
    ui->radioKlient->setEnabled(false);
    ustawKontrolke("green");
    QString ip = klient->peerAddress().toString();
    if (ip.startsWith("::ffff:")) ip = ip.mid(7);
    wyswietlKomunikat("Połączono z serwerem: " + klient->peerAddress().toString());

    rozlaczonoRecznie = false;
    reconnector->stop();
}

void dialog_sieciowy::rozlaczonoZSerwerem()
{
    ustawKontrolke("red");
    wyswietlKomunikat("Rozłączono przez serwer.");
    QTimer::singleShot(2000, this, [=]() { ustawKontrolke("gray"); });
    if (!rozlaczonoRecznie) {
        reconnector->start();
    }
}

void dialog_sieciowy::on_btnRozlaczKlient_clicked()
{
    rozlaczonoRecznie = true;
    reconnector->stop();
    ui->btnPolaczKlient->setEnabled(true);
    ui->radioSerwer->setEnabled(true);
    ui->radioKlient->setEnabled(true);
    klient->disconnectFromHost();
    ustawKontrolke("orange");
    wyswietlKomunikat("Rozłączono klienta.");
}

void dialog_sieciowy::bladPolaczenia(QAbstractSocket::SocketError)
{
    ustawKontrolke("red");
    wyswietlKomunikat("Błąd połączenia z serwerem.");
}

void dialog_sieciowy::migajKontrolka(const QString &kolor1, const QString &kolor2)
{
    ustawKontrolke(kolor1); // jasnozielony
    QTimer::singleShot(150, this, [=]() {
        ustawKontrolke("#006400"); // ciemna zieleń
        QTimer::singleShot(150, this, [=]() {
            ustawKontrolke(kolor1); // znowu jasnozielony
        });
    });
}
void dialog_sieciowy::resetujKontrolke()
{
    ustawKontrolke(aktualnyKolor);
    migacz->stop();
}

void dialog_sieciowy::ustawKontrolke(const QString &kolor)
{
    ui->kontrolkaStatus->setStyleSheet("background-color: " + kolor);
}

void dialog_sieciowy::wyswietlKomunikat(const QString &tekst)
{
    ui->labelStatus->setText(tekst);
}

void dialog_sieciowy::pokazElementySerwera(bool widoczne)
{
    ui->linePortSerwer->setVisible(widoczne);
    ui->btnStartSerwer->setVisible(widoczne);
    ui->btnStopSerwer->setVisible(widoczne);
}

void dialog_sieciowy::pokazElementyKlienta(bool widoczne)
{
    ui->lineIP->setVisible(widoczne);
    ui->linePortKlient->setVisible(widoczne);
    ui->btnPolaczKlient->setVisible(widoczne);
    ui->btnRozlaczKlient->setVisible(widoczne);
}
