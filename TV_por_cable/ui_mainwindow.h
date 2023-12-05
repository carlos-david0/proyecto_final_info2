/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QPushButton *jugar;
    QLCDNumber *puntuacion;
    QLabel *gameover;
    QLCDNumber *puntuaciongo;
    QLabel *instruccion;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(691, 391);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(10, 10, 671, 371));
        jugar = new QPushButton(centralwidget);
        jugar->setObjectName("jugar");
        jugar->setGeometry(QRect(310, 240, 75, 24));
        QFont font;
        font.setFamilies({QString::fromUtf8("Noto Serif Cond")});
        jugar->setFont(font);
        jugar->setCursor(QCursor(Qt::PointingHandCursor));
        puntuacion = new QLCDNumber(centralwidget);
        puntuacion->setObjectName("puntuacion");
        puntuacion->setGeometry(QRect(610, 20, 64, 23));
        gameover = new QLabel(centralwidget);
        gameover->setObjectName("gameover");
        gameover->setGeometry(QRect(270, 150, 151, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Source Code Pro")});
        font1.setPointSize(20);
        font1.setBold(true);
        gameover->setFont(font1);
        gameover->setAlignment(Qt::AlignCenter);
        puntuaciongo = new QLCDNumber(centralwidget);
        puntuaciongo->setObjectName("puntuaciongo");
        puntuaciongo->setGeometry(QRect(300, 210, 91, 23));
        instruccion = new QLabel(centralwidget);
        instruccion->setObjectName("instruccion");
        instruccion->setGeometry(QRect(250, 200, 191, 16));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Rubik")});
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setItalic(true);
        instruccion->setFont(font2);
        instruccion->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(200, 60, 291, 271));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        label->setFont(font3);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 31, 31));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        jugar->setText(QCoreApplication::translate("MainWindow", "Jugar", nullptr));
        gameover->setText(QCoreApplication::translate("MainWindow", "Game over", nullptr));
        instruccion->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
