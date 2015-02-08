/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QRadioButton *rb1;
    QRadioButton *rb2;
    QRadioButton *rb3;
    QPushButton *pushButton;
    QPushButton *aceptar;
    QLabel *label;

    void setupUi(QDialog *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QStringLiteral("Options"));
        Options->resize(236, 185);
        rb1 = new QRadioButton(Options);
        rb1->setObjectName(QStringLiteral("rb1"));
        rb1->setGeometry(QRect(20, 40, 161, 26));
        rb1->setChecked(true);
        rb2 = new QRadioButton(Options);
        rb2->setObjectName(QStringLiteral("rb2"));
        rb2->setGeometry(QRect(20, 70, 151, 26));
        rb2->setCheckable(true);
        rb3 = new QRadioButton(Options);
        rb3->setObjectName(QStringLiteral("rb3"));
        rb3->setGeometry(QRect(20, 100, 211, 26));
        pushButton = new QPushButton(Options);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(124, 140, 71, 31));
        aceptar = new QPushButton(Options);
        aceptar->setObjectName(QStringLiteral("aceptar"));
        aceptar->setGeometry(QRect(40, 140, 71, 31));
        label = new QLabel(Options);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(3, 10, 231, 21));

        retranslateUi(Options);
        QObject::connect(pushButton, SIGNAL(clicked()), Options, SLOT(close()));

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QDialog *Options)
    {
        Options->setWindowTitle(QApplication::translate("Options", "Opciones de Juego", 0));
        rb1->setText(QApplication::translate("Options", "Juego Normal.", 0));
        rb2->setText(QApplication::translate("Options", "Juego Q sobre K.", 0));
        rb3->setText(QApplication::translate("Options", "Juego Q sobre K, A sobre K.", 0));
        pushButton->setText(QApplication::translate("Options", "Cancelar", 0));
        aceptar->setText(QApplication::translate("Options", "Aceptar", 0));
        label->setText(QApplication::translate("Options", "Selecione el modo de juego.", 0));
    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
