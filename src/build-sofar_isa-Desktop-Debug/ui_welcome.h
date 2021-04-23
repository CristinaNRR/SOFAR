/********************************************************************************
** Form generated from reading UI file 'welcome.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOME_H
#define UI_WELCOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_welcome
{
public:
    QWidget *centralWidget;
    QPushButton *start;
    QTextEdit *textEdit;
    QLabel *picture;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *welcome)
    {
        if (welcome->objectName().isEmpty())
            welcome->setObjectName(QStringLiteral("welcome"));
        welcome->resize(597, 457);
        centralWidget = new QWidget(welcome);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(230, 350, 111, 51));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(90, 0, 401, 131));
        picture = new QLabel(centralWidget);
        picture->setObjectName(QStringLiteral("picture"));
        picture->setGeometry(QRect(140, 140, 300, 200));
        welcome->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(welcome);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 597, 22));
        welcome->setMenuBar(menuBar);
        mainToolBar = new QToolBar(welcome);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        welcome->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(welcome);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        welcome->setStatusBar(statusBar);

        retranslateUi(welcome);

        QMetaObject::connectSlotsByName(welcome);
    } // setupUi

    void retranslateUi(QMainWindow *welcome)
    {
        welcome->setWindowTitle(QApplication::translate("welcome", "welcome", Q_NULLPTR));
        start->setText(QApplication::translate("welcome", "Start", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("welcome", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:22pt; font-weight:600;\">WELCOME!</span></p>\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">With this interface you can decide where to send the Turtlebot. The available rooms are the ones shown on the below map:</span></p></body></html>", Q_NULLPTR));
        picture->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class welcome: public Ui_welcome {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOME_H
