#ifndef WIN_SERVER_H
#define WIN_SERVER_H

#include <QtWidgets>
#include <QtNetwork>
#include <QtCore>
//#include <qt_windows.h>

#include <QLabel>

class win_server : public QWidget
{
  Q_OBJECT

private:
    QLabel *_server_condition;
    QPushButton *_quit_button;

    quint16 _message_size;
    QTcpServer *_server;
    QList <QTcpSocket *> _client;


public slots:
    void new_connection(); //initiate a new server connection
    void revceived_data();
    void log_out(); // when a client log-out of the chat

public:
    win_server();

    void send_to_all(const QString &message);



};



#endif // WIN_SERVER_H
