/********************************************************************************
** Form generated from reading UI file 'menuwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUWINDOW_H
#define UI_MENUWINDOW_H

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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menuWindow
{
public:
    QWidget *centralWidget;
    QPushButton *room1;
    QPushButton *room2;
    QPushButton *room3;
    QLabel *label;
    QPushButton *exit;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *menuWindow)
    {
        if (menuWindow->objectName().isEmpty())
            menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuWindow->resize(677, 476);
        centralWidget = new QWidget(menuWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        room1 = new QPushButton(centralWidget);
        room1->setObjectName(QStringLiteral("room1"));
        room1->setGeometry(QRect(70, 100, 121, 61));
        room2 = new QPushButton(centralWidget);
        room2->setObjectName(QStringLiteral("room2"));
        room2->setGeometry(QRect(280, 100, 121, 61));
        room3 = new QPushButton(centralWidget);
        room3->setObjectName(QStringLiteral("room3"));
        room3->setGeometry(QRect(510, 100, 121, 61));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(270, 200, 541, 71));
        label->setMinimumSize(QSize(541, 71));
        exit = new QPushButton(centralWidget);
        exit->setObjectName(QStringLiteral("exit"));
        exit->setGeometry(QRect(270, 300, 141, 41));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 10, 301, 61));
        QFont font;
        font.setPointSize(17);
        label_2->setFont(font);
        menuWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(menuWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 677, 22));
        menuWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(menuWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        menuWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(menuWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        menuWindow->setStatusBar(statusBar);

        retranslateUi(menuWindow);

        QMetaObject::connectSlotsByName(menuWindow);
    } // setupUi

    void retranslateUi(QMainWindow *menuWindow)
    {
        menuWindow->setWindowTitle(QApplication::translate("menuWindow", "menuWindow", Q_NULLPTR));
        room1->setText(QApplication::translate("menuWindow", "Room 1", Q_NULLPTR));
        room2->setText(QApplication::translate("menuWindow", "Room 2", Q_NULLPTR));
        room3->setText(QApplication::translate("menuWindow", "Room 3", Q_NULLPTR));
        label->setText(QApplication::translate("menuWindow", "          Status", Q_NULLPTR));
        exit->setText(QApplication::translate("menuWindow", "Exit The Menu", Q_NULLPTR));
        label_2->setText(QApplication::translate("menuWindow", "Where do you want to go?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class menuWindow: public Ui_menuWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUWINDOW_H
