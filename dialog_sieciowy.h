#ifndef DIALOG_SIECIOWY_H
#define DIALOG_SIECIOWY_H

#include <QDialog>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTimer>

namespace Ui {
class dialog_sieciowy;
}

class dialog_sieciowy : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_sieciowy(QWidget *parent = nullptr);
    ~dialog_sieciowy();

private slots:
    void on_btnWlaczSiec_clicked();
    void on_radioSerwer_toggled(bool checked);
    void on_radioKlient_toggled(bool checked);
    void on_btnStartSerwer_clicked();
    void on_btnPolaczKlient_clicked();
    void nowyKlient();
    void klientRozlaczyl();
    void polaczonoZSerwerem();
    void rozlaczonoZSerwerem();
    void bladPolaczenia(QAbstractSocket::SocketError blad);
    void migajKontrolka(const QString &kolor1, const QString &kolor2);
    void resetujKontrolke();

    void on_btnStopSerwer_clicked();
    void on_btnRozlaczKlient_clicked();

private:
    Ui::dialog_sieciowy *ui;
    QTcpServer *serwer;
    QTcpSocket *polaczoneGniazdo;
    QTcpSocket *klient;
    QTimer *migacz;
    QString aktualnyKolor;
    bool trybSieciowyWlaczony;
    QTimer *reconnector;

    void ustawKontrolke(const QString &kolor);
    void wyswietlKomunikat(const QString &tekst);
    void pokazElementySerwera(bool widoczne);
    void pokazElementyKlienta(bool widoczne);
};

#endif // DIALOG_SIECIOWY_H
