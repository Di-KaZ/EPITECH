// //
// // EPITECH PROJECT, 2018
// // babel
// // File description:
// //
// //

// #include "BabelTcpClient.hpp"
// #include "main.hpp"
// #include <stdio.h>
// #include <opus/opus.h>
// #include <portaudio.h>
// #include <QtWidgets/QApplication>
// #include <QtWidgets/QPushButton>
// #include <boost/asio.hpp>
// #include <boost/array.hpp>
// #include <iostream>

// void BabelTcpClient::connected()
// {
//     printf("lol");
// }

// void connectTcp()
// {
//     QByteArray data;
//     QTcpSocket * _pSocket;
//     int lol;

//     _pSocket = new QTcpSocket();
//     //connect( lol, SIGNAL(readyRead()), SLOT(readTcpData(_pSocket)));

//     _pSocket->connectToHost("127.0.0.1", 8080);
//     if( _pSocket->waitForConnected() ) {
//         printf("%s\n", "lol");
//         _pSocket->write( data );
//     }
// }

// void readTcpData(QTcpSocket * _pSocket)
// {
//     QByteArray data = _pSocket->readAll();
//     printf(data );
// }

// // ButtonConnect::ButtonConnect(QWidget *parent) : QWidget(parent) {
// //     this->Connect = new QPushButton("Connect", this);
// //     this->Connect->setObjectName(QStringLiteral("ButtonConnect"));
// //     this->Connect->setGeometry(QRect(50, 110, 61, 21));
// //     this->Connect->setStyleSheet(QStringLiteral("background-color:rgb(0, 170, 255)"));
// //     this->Connect->setText(QApplication::translate("Form", "Connect", Q_NULLPTR));
// //     connect(this->Connect, &QPushButton::clicked, this, &ButtonConnect::connected);
// // }
// //
// // ButtonConnect::~ButtonConnect(){
// // }
// //
// // void ButtonConnect::connected() {
// //     printf("lol");
// // }
