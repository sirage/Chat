#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void button_connection_clicked();
    void button_send_clicked();
    void massege_return_pressed();
    void received_data();
    void connect();
    void disconnect();
    void socket_error(QAbstractSocket::SocketError error);


private:
    Ui::MainWindow *ui;
    QTcpSocket *_socket;
    quint16 _massege_size;

};

#endif // MAINWINDOW_H
