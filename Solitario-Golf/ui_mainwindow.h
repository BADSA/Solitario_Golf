/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

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

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *inicaJuego;
    QPushButton *close;
    QLabel *lb1;
    QPushButton *IniRap;
    QPushButton *opt;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(249, 248);
        MainWindow->setMaximumSize(QSize(249, 248));
        MainWindow->setSizeIncrement(QSize(249, 248));
        MainWindow->setAnimated(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        inicaJuego = new QPushButton(centralWidget);
        inicaJuego->setObjectName(QStringLiteral("inicaJuego"));
        inicaJuego->setGeometry(QRect(40, 30, 171, 31));
        inicaJuego->setFocusPolicy(Qt::NoFocus);
        inicaJuego->setProperty("Value", QVariant(1));
        close = new QPushButton(centralWidget);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(40, 150, 171, 31));
        lb1 = new QLabel(centralWidget);
        lb1->setObjectName(QStringLiteral("lb1"));
        lb1->setGeometry(QRect(10, 0, 181, 21));
        IniRap = new QPushButton(centralWidget);
        IniRap->setObjectName(QStringLiteral("IniRap"));
        IniRap->setGeometry(QRect(40, 70, 171, 31));
        opt = new QPushButton(centralWidget);
        opt->setObjectName(QStringLiteral("opt"));
        opt->setGeometry(QRect(40, 110, 171, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 249, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(close, SIGNAL(clicked()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Solitario Golf", 0));
        inicaJuego->setText(QApplication::translate("MainWindow", "Iniciar Juego 9 Rondas", 0));
        close->setText(QApplication::translate("MainWindow", "Salir", 0));
        lb1->setText(QApplication::translate("MainWindow", "Solitario Golf.", 0));
        IniRap->setText(QApplication::translate("MainWindow", "Juego Rapido", 0));
        opt->setText(QApplication::translate("MainWindow", "Opciones", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
