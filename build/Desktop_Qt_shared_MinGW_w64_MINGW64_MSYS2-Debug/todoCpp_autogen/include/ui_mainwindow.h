/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *taskInput;
    QListWidget *taskList;
    QPushButton *addButton;
    QPushButton *doneButton;
    QPushButton *editButton;
    QPushButton *removeButton;
    QPushButton *removeAllButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1092, 1112);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        taskInput = new QLineEdit(centralwidget);
        taskInput->setObjectName("taskInput");
        taskInput->setGeometry(QRect(300, 7, 351, 41));
        taskList = new QListWidget(centralwidget);
        taskList->setObjectName("taskList");
        taskList->setGeometry(QRect(300, 60, 441, 541));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(660, 8, 83, 41));
        doneButton = new QPushButton(centralwidget);
        doneButton->setObjectName("doneButton");
        doneButton->setGeometry(QRect(360, 610, 83, 29));
        editButton = new QPushButton(centralwidget);
        editButton->setObjectName("editButton");
        editButton->setGeometry(QRect(450, 610, 83, 29));
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");
        removeButton->setGeometry(QRect(540, 610, 83, 29));
        removeAllButton = new QPushButton(centralwidget);
        removeAllButton->setObjectName("removeAllButton");
        removeAllButton->setGeometry(QRect(632, 610, 111, 29));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        doneButton->setText(QCoreApplication::translate("MainWindow", "Done", nullptr));
        editButton->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "remove", nullptr));
        removeAllButton->setText(QCoreApplication::translate("MainWindow", "remove all", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
