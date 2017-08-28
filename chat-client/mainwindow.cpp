 #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    _socket = new QTcpSocket(this);
    QObject::connect(_socket,SIGNAL(readyRead()),this,SLOT(received_data()));
    QObject::connect(_socket,SIGNAL(connected()),this,SLOT(connect()));
    QObject::connect(_socket,SIGNAL(disconnected()),this,SLOT(disconnect()));
    QObject::connect(_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,
                     SLOT(socket_error(QAbstractSocket::SocketError)));
    _massege_size = 0;
    
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::button_connection_clicked()
{
    ui->_chat_text->append("Attempting to connect...");
    ui->_connection_button->setEnabled(false);

    _socket->abort(); //disactivateing previous connection if there was some
    _socket->connectToHost(ui->_server_ip->text(), ui->_port->value()); //connectToHost(const QString & hostname,quint16 prot)

}

void MainWindow::button_send_clicked() //used to send a massege
{
    QByteArray package;
    QDataStream out(&package, QIODevice::WriteOnly);

    //preparing the package to be sended
    QString massege_to_be_sended = ("<strong>") + ui->_psuedo->text() + ("</strong> : ")
            + ui->_massege->text();

    out <<(quint16) 0; //reserving the 0 position to write the size of the package
    out << massege_to_be_sended; //write the massege into the package
    out.device()->seek(0); //we gonna be placed into [0]
    out << (quint16) (package.size() - sizeof(quint16)); //deleting teh [0] position
    _socket->write(package);
    ui->_massege->clear();

    //ui->_massege->setFocus(); //put the cursor in the ???

}

void MainWindow::massege_return_pressed()
{
    button_send_clicked();
}

    

void MainWindow::received_data()
{
    QDataStream in(_socket);
    if(_massege_size == 0)
    {
        if(_socket->bytesAvailable() < (int)sizeof(quint16))
        {
            return;
            in>>_massege_size;
        }
        if (_socket->bytesAvailable()<_massege_size)
        {
            return;
        }
        
        QString massegeReceived;
        in >> massegeReceived; 

        ui->_chat_text->append(massegeReceived);

        _massege_size = 0;

    }
    
}

//This Slot is called when the connection is established
void MainWindow::connect()
{
    ui->_chat_text->append("Connection Succeful");
    ui->_connection_button->setEnabled(true);
}


void MainWindow::disconnect()
{
    ui->_chat_text->append("Disconnected from the server");
}



//this slot is called when the client has disconnected
void MainWindow::socket_error(QAbstractSocket::SocketError error)
{
    switch (error) {
    case QAbstractSocket::HostNotFoundError:
        ui->_chat_text->append("ERROR : Check the Ip and prot of your server");
        break;

    case QAbstractSocket::ConnectionRefusedError:
        ui->_chat_text->append("ERROR : check if the server is lunched and chen the ip and port of your server");

    case QAbstractSocket::RemoteHostClosedError:
        ui->_chat_text->append("ERROR : the server has disconnectd");
    default:
        ui->_chat_text->append(("ERROR : ") + _socket->errorString());
        break;

        ui->_connection_button->setEnabled(true);
    }

}









