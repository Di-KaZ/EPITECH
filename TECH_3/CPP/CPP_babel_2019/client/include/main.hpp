/********************************************************************************
** Form generated from reading UI file 'qtdesign.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTDESIGN_H
#define UI_QTDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QTextBrowser *textBrowser;
    QTextEdit *Ip;
    QPushButton *ButtonConnect;
    QPushButton *ButtonDecline;
    QPushButton *ButtonAccept;
    QTextBrowser *textBrowser_2;
    QTextEdit *Port;
    QTextBrowser *textBrowser_3;
    QTextEdit *UserName;
    QTextBrowser *textBrowser_4;
    QTextBrowser *textBrowser_5;
    QTextBrowser *textBrowser_6;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QWidget window;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(469, 403);
        textBrowser = new QTextBrowser(Form);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 30, 81, 31));
        Ip = new QTextEdit(Form);
        Ip->setObjectName(QStringLiteral("Ip"));
        Ip->setGeometry(QRect(100, 30, 101, 31));
        ButtonConnect = new QPushButton(Form);
        ButtonConnect->setObjectName(QStringLiteral("ButtonConnect"));
        ButtonConnect->setGeometry(QRect(70, 180, 61, 21));
        ButtonConnect->setStyleSheet(QStringLiteral("background-color:rgb(0, 170, 255)"));
        ButtonDecline = new QPushButton(Form);
        ButtonDecline->setObjectName(QStringLiteral("ButtonDecline"));
        ButtonDecline->setGeometry(QRect(100, 310, 61, 21));
        ButtonDecline->setStyleSheet(QStringLiteral("background-color:rgb(255, 0, 0)"));
        ButtonAccept = new QPushButton(Form);
        ButtonAccept->setObjectName(QStringLiteral("ButtonAccept"));
        ButtonAccept->setGeometry(QRect(20, 310, 61, 21));
        ButtonAccept->setStyleSheet(QStringLiteral("background-color:rgb(0, 255, 0)"));
        textBrowser_2 = new QTextBrowser(Form);
        textBrowser_2->setObjectName(QStringLiteral("textBrowser_2"));
        textBrowser_2->setGeometry(QRect(10, 80, 81, 31));
        Port = new QTextEdit(Form);
        Port->setObjectName(QStringLiteral("Port"));
        Port->setGeometry(QRect(100, 80, 101, 31));
        textBrowser_3 = new QTextBrowser(Form);
        textBrowser_3->setObjectName(QStringLiteral("textBrowser_3"));
        textBrowser_3->setGeometry(QRect(10, 130, 81, 31));
        UserName = new QTextEdit(Form);
        UserName->setObjectName(QStringLiteral("UserName"));
        UserName->setGeometry(QRect(100, 130, 101, 31));
        textBrowser_4 = new QTextBrowser(Form);
        textBrowser_4->setObjectName(QStringLiteral("textBrowser_4"));
        textBrowser_4->setGeometry(QRect(10, 260, 161, 41));
        textBrowser_5 = new QTextBrowser(Form);
        textBrowser_5->setObjectName(QStringLiteral("textBrowser_5"));
        textBrowser_5->setGeometry(QRect(270, 30, 181, 31));
        textBrowser_5->setStyleSheet(QStringLiteral(""));
        textBrowser_6 = new QTextBrowser(Form);
        textBrowser_6->setObjectName(QStringLiteral("textBrowser_6"));
        textBrowser_6->setGeometry(QRect(270, 70, 181, 221));
        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 360, 56, 17));
        textEdit = new QTextEdit(Form);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(270, 300, 181, 51));
        textBrowser->raise();
        Ip->raise();
        ButtonConnect->raise();
        ButtonDecline->raise();
        ButtonAccept->raise();
        textBrowser_2->raise();
        Port->raise();
        textBrowser_3->raise();
        UserName->raise();
        textBrowser_4->raise();
        textBrowser_5->raise();
        textBrowser_6->raise();
        textEdit->raise();
        pushButton->raise();

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">IP :</p></body></html>", Q_NULLPTR));
        ButtonConnect->setText(QApplication::translate("Form", "Connect", Q_NULLPTR));
        ButtonDecline->setText(QApplication::translate("Form", "Decline", Q_NULLPTR));
        ButtonAccept->setText(QApplication::translate("Form", "Accept", Q_NULLPTR));
        textBrowser_2->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Port :</p></body></html>", Q_NULLPTR));
        textBrowser_3->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Username :</p></body></html>", Q_NULLPTR));
        textBrowser_5->setHtml(QApplication::translate("Form", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Status : Disconnected</p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Form", "Send", Q_NULLPTR));
    } // retranslateUi

};
void connectTcp();
namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTDESIGN_H
