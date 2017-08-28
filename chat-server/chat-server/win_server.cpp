#include <win_server.h>

win_server::win_server()
{
    _server_condition = new QLabel;

    _quit_button = new QPushButton("Quit");
    QObject::connect(_quit_button,SIGNAL(clicked()),qApp,SLOT(quit()));

    QVBoxLayout *layout = new QVBoxLayout;
    layout -> addWidget(_server_condition);
    layout -> addWidget(_quit_button);
    setLayout(layout);


    setWindowTitle("chat-server");



    _server = new QTcpServer(this);
    if(!_server->listen(QHostAddress::Any,50885))
    {
        _server_condition->setText(tr("The server couldnt be started, the reason is : ")+
                                   _server->errorString());
    }
    else
    {
        _server_condition->setText(tr("The server has started on the port ") +
                                   QString::number(_server->serverPort()));
        QObject::connect(_server,SIGNAL(newConnection()),this,SLOT(new_connection()));
    }

    _message_size = 0;

}



void win_server::new_connection()
{
    
    QTcpSocket *new_client = _server->nextPendingConnection(); //QTcpsocket = establish a new TCP connection
    _client << new_client;
    QObject::connect(new_client,SIGNAL(readyRead()),this,SLOT(revceived_data()));
    QObject::connect(new_client,SIGNAL(disconnected()),this,SLOT(log_out()));
}





void win_server::revceived_data()
{
    //receiving the package from the client
    //reseearching the client who sended the package (by searching the QTcpsocket from the client)


    //if we didnt knew the client which was the origine of the signal we ==> stopping the method
   QTcpSocket *socket = qobject_cast<QTcpSocket *> (sender());
   if(socket ==0)
   {
       return;
   }
    //if all is good we continue.....we get the message

   //if we dont know the message size we try getting the size
   QDataStream in(socket);
   if(_message_size == 0)
   {
       //we didnt receive the entire package
       if(socket->bytesAvailable() < (int)sizeof(quint16) )
       {
           return;
       }

       //we get message size
       in>>_message_size;
   }

   //if we didnt recieve every thing wze stop the method
   if(socket->bytesAvailable() < _message_size)
   {
       return;
   }

   QString message;
   in >> message;

   send_to_all(message);

   _message_size = 0;

}



void win_server::log_out()
{
    send_to_all(tr("a client has disconnected"));

    QTcpSocket *socket = qobject_cast<QTcpSocket *> (sender());
    if(socket == 0)
    {
        return;
    }

    _client.removeOne(socket);
    socket -> deleteLater();

}



void win_server::send_to_all(const QString &message)
{
    QByteArray package;
    QDataStream out(&package,QIODevice::WriteOnly);

    out << (quint16) 0;
    out << message;
    out.device()->seek(0);

    out<<(quint16)(package.size() - sizeof(quint16));


    for(int i=0; i< _client.size();i++)
    {
        _client[i]->write(package);
    }
}


























