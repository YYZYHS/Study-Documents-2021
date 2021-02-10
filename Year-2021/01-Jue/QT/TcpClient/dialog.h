#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QHostAddress>
#include <QTcpSocket>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QGridLayout>
class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);
    ~Dialog();
private:
    bool status;
    int port;
    QHostAddress *serverIP;
    QString userName;
    QTcpSocket *tcpSocket;

    QLabel *userNameLabel;
    QLabel *serverIPLabel;
    QLabel *portLabel;
    QLineEdit *sendLineEdit;
    QLineEdit *portLineEdit;
    QLineEdit *serverIPLineEdit;
    QLineEdit *userNameLineEdit;
    QPushButton *enterBtn;
    QPushButton *sendBtn;
    QListWidget *contentListWidget;
    QGridLayout *mainLayout;
public slots:
    void slotEnter();
    void slotConnected();
    void slotDisconnected();
    void dataReceived();
    void slotSend();
};

#endif // DIALOG_H
