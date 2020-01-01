// /*
// ** EPITECH PROJECT, 2019
// ** CPP_babel_2019
// ** File description:
// ** IClient.hpp
// */

// #pragma once

// #include <QtCore/QVariant>
// #include <QWidget>
// #include <QtWidgets/QAction>
// #include <QtWidgets/QApplication>
// #include <QtWidgets/QButtonGroup>
// #include <QtWidgets/QHeaderView>
// #include <QtWidgets/QPushButton>
// #include <QtWidgets/QTextBrowser>
// #include <QtWidgets/QTextEdit>
// #include <QtWidgets/QWidget>
// #include <QtNetwork>

// class IClient : public QWidget{
//     public:
//         virtual ~IClient()
//         {

//         };
//         /*
//         ** Send data to Server
//         */
//         virtual void sendData(void *data, long unsigned int &size) = 0;
//         /*
//         ** Read data from Server
//         */
//         virtual void readData(void *data, long unsigned int &size) = 0;
//         /*
//         ** Connect client to Server
//         */
//         virtual void connectToServer(void *data, long unsigned int &size) = 0;
//     private:
//         QByteArray dataToSend;
//         QByteArray dataToRead;
// };