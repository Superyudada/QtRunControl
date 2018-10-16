/********************************************************************************
** Form generated from reading UI file 'QtRunControl.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTRUNCONTROL_H
#define UI_QTRUNCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtRunControlClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtRunControlClass)
    {
        if (QtRunControlClass->objectName().isEmpty())
            QtRunControlClass->setObjectName(QStringLiteral("QtRunControlClass"));
        QtRunControlClass->resize(876, 860);
        centralWidget = new QWidget(QtRunControlClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 10, 211, 101));
        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(260, 10, 581, 771));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(30, 130, 211, 101));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(30, 250, 211, 111));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 390, 211, 111));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(30, 530, 211, 111));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(30, 660, 211, 121));
        QtRunControlClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QtRunControlClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 876, 26));
        QtRunControlClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtRunControlClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtRunControlClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtRunControlClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtRunControlClass->setStatusBar(statusBar);

        retranslateUi(QtRunControlClass);
        QObject::connect(pushButton, SIGNAL(clicked()), QtRunControlClass, SLOT(prepare()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), QtRunControlClass, SLOT(ready()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), QtRunControlClass, SLOT(run()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), QtRunControlClass, SLOT(pause()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), QtRunControlClass, SLOT(continuE()));

        QMetaObject::connectSlotsByName(QtRunControlClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtRunControlClass)
    {
        QtRunControlClass->setWindowTitle(QApplication::translate("QtRunControlClass", "QtRunControl", nullptr));
        pushButton->setText(QApplication::translate("QtRunControlClass", "prepare", nullptr));
        pushButton_2->setText(QApplication::translate("QtRunControlClass", "ready", nullptr));
        pushButton_3->setText(QApplication::translate("QtRunControlClass", "run", nullptr));
        pushButton_4->setText(QApplication::translate("QtRunControlClass", "pause", nullptr));
        pushButton_5->setText(QApplication::translate("QtRunControlClass", "continue", nullptr));
        pushButton_6->setText(QApplication::translate("QtRunControlClass", "end", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtRunControlClass: public Ui_QtRunControlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTRUNCONTROL_H
