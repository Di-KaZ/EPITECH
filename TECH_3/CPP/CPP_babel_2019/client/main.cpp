//
// EPITECH PROJECT, 2018
// babel
// File description:
//
//

#include "BabelTcpClient.hpp"
#include "main.hpp"
#include <stdio.h>
#include <opus/opus.h>
#include <portaudio.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

/*#include <QApplication>
#include <QWidget>
#include <QPushButton>

class MyButton : public QWidget, public QObject {
    Q_OBJECT
public:
explicit MyButton(QObject *parent = 0);
    MyButton(QWidget *parent = 0);

signals:

public slots:

    void connected();
};

MyButton::MyButton(QWidget *parent) : QWidget(parent), QObject(parent) {
    QPushButton *quitBtn = new QPushButton("Quit", this);
    quitBtn->setGeometry(50, 40, 75, 30);

    connect(quitBtn, SIGNAL(clicked()), qApp, SLOT(connected()));
}

void MyButton::connected()
{
    printf("lol");
}

int main(int argc, char *argv[]) {

  QApplication app(argc, argv);

  MyButton window;

  window.resize(250, 150);
  window.setWindowTitle("QPushButton");
  window.show();

  return app.exec();
}*/

// int main(int argc, char **argv)
// {
//     QApplication *app = new QApplication(argc, argv);
//     BabelTcpClient client;
//     Ui_Form test;
//     QWidget window;
//     test.window.resize(250, 150);
//     test.window.setWindowTitle("ALIIII");
//     test.setupUi(&test.window);
//     //ButtonConnect buttonCo(&test.window);
//     test.window.show();
//     connectTcp();
//     //printf("%s\n", test.Ip->toPlainText());

//     return app->exec();
// }

/*
** Main pour tester le serveur udp
**
*/

/*int main (int ac, char **av)
{
    boost::asio::io_service io_service;
    boost::asio::ip::udp::endpoint receiver_endpoint(boost::asio::ip::address::from_string("127.0.0.1"), 8080);
    boost::asio::ip::udp::socket socket(io_service);
    socket.open(boost::asio::ip::udp::v4());
	std::string message = "yay";
    //
	socket.send_to(boost::asio::buffer(message), receiver_endpoint);
    boost::array<char, 128> recv_buf;
	boost::asio::ip::udp::endpoint sender_endpoint;
	size_t len = socket.receive_from(boost::asio::buffer(recv_buf), sender_endpoint);
	std::cout.write(recv_buf.data(), len);
    return (0);
}*/
#include "CoreClient.hpp"

int main(int ac, char **av)
{
    if (ac != 3)
        return 84;
    CoreClient cli(av[1], std::atoi(av[2]));
    cli.run();
}