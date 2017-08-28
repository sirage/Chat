/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTextEdit *_chat_text;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *_server_ip_txt;
    QLineEdit *_server_ip;
    QSpacerItem *horizontalSpacer;
    QLabel *_port_txt;
    QSpinBox *_port;
    QPushButton *_connection_button;
    QSpacerItem *horizontalSpacer_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *_psuedo_txt;
    QLineEdit *_psuedo;
    QSpacerItem *horizontalSpacer_3;
    QLabel *_massege_txt;
    QLineEdit *_massege;
    QPushButton *_send_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1160, 783);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        _chat_text = new QTextEdit(centralWidget);
        _chat_text->setObjectName(QStringLiteral("_chat_text"));
        _chat_text->setGeometry(QRect(10, 90, 1141, 531));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1141, 71));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        _server_ip_txt = new QLabel(layoutWidget);
        _server_ip_txt->setObjectName(QStringLiteral("_server_ip_txt"));

        horizontalLayout->addWidget(_server_ip_txt);

        _server_ip = new QLineEdit(layoutWidget);
        _server_ip->setObjectName(QStringLiteral("_server_ip"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(_server_ip->sizePolicy().hasHeightForWidth());
        _server_ip->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(_server_ip);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _port_txt = new QLabel(layoutWidget);
        _port_txt->setObjectName(QStringLiteral("_port_txt"));

        horizontalLayout->addWidget(_port_txt);

        _port = new QSpinBox(layoutWidget);
        _port->setObjectName(QStringLiteral("_port"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(_port->sizePolicy().hasHeightForWidth());
        _port->setSizePolicy(sizePolicy1);
        _port->setMaximum(10000000);

        horizontalLayout->addWidget(_port);

        _connection_button = new QPushButton(layoutWidget);
        _connection_button->setObjectName(QStringLiteral("_connection_button"));

        horizontalLayout->addWidget(_connection_button);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 630, 1131, 81));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        _psuedo_txt = new QLabel(layoutWidget1);
        _psuedo_txt->setObjectName(QStringLiteral("_psuedo_txt"));

        horizontalLayout_2->addWidget(_psuedo_txt);

        _psuedo = new QLineEdit(layoutWidget1);
        _psuedo->setObjectName(QStringLiteral("_psuedo"));

        horizontalLayout_2->addWidget(_psuedo);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        _massege_txt = new QLabel(layoutWidget1);
        _massege_txt->setObjectName(QStringLiteral("_massege_txt"));

        horizontalLayout_2->addWidget(_massege_txt);

        _massege = new QLineEdit(layoutWidget1);
        _massege->setObjectName(QStringLiteral("_massege"));
        sizePolicy.setHeightForWidth(_massege->sizePolicy().hasHeightForWidth());
        _massege->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(_massege);

        _send_button = new QPushButton(layoutWidget1);
        _send_button->setObjectName(QStringLiteral("_send_button"));
        _send_button->setStyleSheet(QStringLiteral(""));

        horizontalLayout_2->addWidget(_send_button);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1160, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        _server_ip_txt->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Server Ip</span></p></body></html>", Q_NULLPTR));
        _port_txt->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Port</span></p></body></html>", Q_NULLPTR));
        _connection_button->setText(QApplication::translate("MainWindow", "Connection", Q_NULLPTR));
        _psuedo_txt->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Psuedo</span></p></body></html>", Q_NULLPTR));
        _massege_txt->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Massege</span></p></body></html>", Q_NULLPTR));
        _send_button->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
