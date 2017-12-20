/********************************************************************************
** Form generated from reading UI file 'activate.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVATE_H
#define UI_ACTIVATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_activateClass
{
public:
    QWidget *centralWidget;
    QLabel *numberlabel;
    QPushButton *activatePushButton;
    QLineEdit *lineEdit;
    QLabel *networkStatelabel;
    QLabel *statelabel;
    QPushButton *connectPushButton;
    QPushButton *clearPushButton;
    QLabel *noticeLabel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *activateClass)
    {
        if (activateClass->objectName().isEmpty())
            activateClass->setObjectName(QStringLiteral("activateClass"));
        activateClass->resize(480, 120);
        activateClass->setMinimumSize(QSize(480, 120));
        activateClass->setMaximumSize(QSize(480, 120));
        centralWidget = new QWidget(activateClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        numberlabel = new QLabel(centralWidget);
        numberlabel->setObjectName(QStringLiteral("numberlabel"));
        numberlabel->setGeometry(QRect(10, 30, 71, 20));
        numberlabel->setStyleSheet(QStringLiteral("background-color: rgb(85, 170, 127);"));
        activatePushButton = new QPushButton(centralWidget);
        activatePushButton->setObjectName(QStringLiteral("activatePushButton"));
        activatePushButton->setGeometry(QRect(380, 30, 51, 20));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 30, 281, 20));
        networkStatelabel = new QLabel(centralWidget);
        networkStatelabel->setObjectName(QStringLiteral("networkStatelabel"));
        networkStatelabel->setGeometry(QRect(10, 0, 54, 20));
        statelabel = new QLabel(centralWidget);
        statelabel->setObjectName(QStringLiteral("statelabel"));
        statelabel->setGeometry(QRect(70, 0, 61, 20));
        statelabel->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        connectPushButton = new QPushButton(centralWidget);
        connectPushButton->setObjectName(QStringLiteral("connectPushButton"));
        connectPushButton->setGeometry(QRect(140, 0, 51, 21));
        clearPushButton = new QPushButton(centralWidget);
        clearPushButton->setObjectName(QStringLiteral("clearPushButton"));
        clearPushButton->setGeometry(QRect(430, 30, 41, 20));
        noticeLabel = new QLabel(centralWidget);
        noticeLabel->setObjectName(QStringLiteral("noticeLabel"));
        noticeLabel->setGeometry(QRect(90, 50, 281, 20));
        noticeLabel->setStyleSheet(QStringLiteral("background-color: rgb(170, 255, 255);"));
        activateClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(activateClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 480, 23));
        activateClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(activateClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        activateClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(activateClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        activateClass->setStatusBar(statusBar);

        retranslateUi(activateClass);

        QMetaObject::connectSlotsByName(activateClass);
    } // setupUi

    void retranslateUi(QMainWindow *activateClass)
    {
        activateClass->setWindowTitle(QApplication::translate("activateClass", "activate", 0));
        numberlabel->setText(QApplication::translate("activateClass", "\346\263\250\345\206\214\345\272\217\345\210\227\345\217\267:", 0));
        activatePushButton->setText(QApplication::translate("activateClass", "\346\277\200\346\264\273", 0));
        networkStatelabel->setText(QApplication::translate("activateClass", "\347\275\221\347\273\234\347\212\266\346\200\201\357\274\232", 0));
        statelabel->setText(QString());
        connectPushButton->setText(QApplication::translate("activateClass", "\350\277\236\346\216\245", 0));
        clearPushButton->setText(QApplication::translate("activateClass", "\346\270\205\351\231\244", 0));
        noticeLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class activateClass: public Ui_activateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVATE_H
