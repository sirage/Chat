#include <QApplication>
#include <QtCore>
#include "win_server.h"

int main(int argc , char * argv[])
{
    QApplication app (argc,argv);

    win_server window;
    window.show();

    return app.exec();
}




