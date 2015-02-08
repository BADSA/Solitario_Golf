/********************************************************************************
** Form generated from reading UI file 'score.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCORE_H
#define UI_SCORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Score
{
public:
    QLabel *lb1;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label;
    QLabel *label_15;
    QFrame *line;
    QLabel *lb_total;
    QLabel *lb_1;
    QLabel *lb_coment;
    QLabel *lb_2;
    QLabel *lb_3;
    QLabel *lb_4;
    QLabel *lb_5;
    QLabel *lb_6;
    QLabel *lb_7;
    QLabel *lb_8;
    QLabel *lb_9;
    QPushButton *aceptar;
    QLabel *lb_coment_2;

    void setupUi(QDialog *Score)
    {
        if (Score->objectName().isEmpty())
            Score->setObjectName(QStringLiteral("Score"));
        Score->resize(257, 366);
        Score->setAutoFillBackground(false);
        lb1 = new QLabel(Score);
        lb1->setObjectName(QStringLiteral("lb1"));
        lb1->setGeometry(QRect(10, 10, 321, 31));
        QFont font;
        font.setFamily(QStringLiteral("Cantarell"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        lb1->setFont(font);
        label_6 = new QLabel(Score);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(60, 220, 111, 21));
        label_7 = new QLabel(Score);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(60, 200, 111, 21));
        label_8 = new QLabel(Score);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(60, 180, 111, 21));
        label_9 = new QLabel(Score);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(60, 160, 111, 21));
        label_10 = new QLabel(Score);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(60, 140, 111, 21));
        label_11 = new QLabel(Score);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(60, 120, 111, 21));
        label_12 = new QLabel(Score);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(60, 100, 111, 21));
        label_13 = new QLabel(Score);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(60, 80, 111, 21));
        label_14 = new QLabel(Score);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(60, 60, 111, 21));
        label = new QLabel(Score);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 141, 21));
        label_15 = new QLabel(Score);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(70, 250, 41, 21));
        line = new QFrame(Score);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(50, 240, 191, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        lb_total = new QLabel(Score);
        lb_total->setObjectName(QStringLiteral("lb_total"));
        lb_total->setGeometry(QRect(140, 250, 64, 21));
        lb_1 = new QLabel(Score);
        lb_1->setObjectName(QStringLiteral("lb_1"));
        lb_1->setGeometry(QRect(130, 60, 81, 21));
        lb_coment = new QLabel(Score);
        lb_coment->setObjectName(QStringLiteral("lb_coment"));
        lb_coment->setGeometry(QRect(40, 270, 211, 21));
        lb_2 = new QLabel(Score);
        lb_2->setObjectName(QStringLiteral("lb_2"));
        lb_2->setGeometry(QRect(130, 80, 81, 21));
        lb_3 = new QLabel(Score);
        lb_3->setObjectName(QStringLiteral("lb_3"));
        lb_3->setGeometry(QRect(130, 100, 81, 21));
        lb_4 = new QLabel(Score);
        lb_4->setObjectName(QStringLiteral("lb_4"));
        lb_4->setGeometry(QRect(130, 120, 81, 21));
        lb_5 = new QLabel(Score);
        lb_5->setObjectName(QStringLiteral("lb_5"));
        lb_5->setGeometry(QRect(130, 140, 81, 21));
        lb_6 = new QLabel(Score);
        lb_6->setObjectName(QStringLiteral("lb_6"));
        lb_6->setGeometry(QRect(130, 160, 81, 21));
        lb_7 = new QLabel(Score);
        lb_7->setObjectName(QStringLiteral("lb_7"));
        lb_7->setGeometry(QRect(130, 180, 81, 21));
        lb_8 = new QLabel(Score);
        lb_8->setObjectName(QStringLiteral("lb_8"));
        lb_8->setGeometry(QRect(130, 200, 81, 21));
        lb_9 = new QLabel(Score);
        lb_9->setObjectName(QStringLiteral("lb_9"));
        lb_9->setGeometry(QRect(130, 220, 81, 21));
        aceptar = new QPushButton(Score);
        aceptar->setObjectName(QStringLiteral("aceptar"));
        aceptar->setGeometry(QRect(50, 320, 161, 31));
        lb_coment_2 = new QLabel(Score);
        lb_coment_2->setObjectName(QStringLiteral("lb_coment_2"));
        lb_coment_2->setGeometry(QRect(40, 290, 211, 21));

        retranslateUi(Score);
        QObject::connect(aceptar, SIGNAL(clicked()), Score, SLOT(close()));

        QMetaObject::connectSlotsByName(Score);
    } // setupUi

    void retranslateUi(QDialog *Score)
    {
        Score->setWindowTitle(QApplication::translate("Score", "Puntuacion del Juego.", 0));
        lb1->setText(QApplication::translate("Score", "Tabla de puntuaciones:", 0));
        label_6->setText(QApplication::translate("Score", "Jugada 9:", 0));
        label_7->setText(QApplication::translate("Score", "Jugada 8:", 0));
        label_8->setText(QApplication::translate("Score", "Jugada 7:", 0));
        label_9->setText(QApplication::translate("Score", "Jugada 6:", 0));
        label_10->setText(QApplication::translate("Score", "Jugada 5:", 0));
        label_11->setText(QApplication::translate("Score", "Jugada 4:", 0));
        label_12->setText(QApplication::translate("Score", "Jugada 3:", 0));
        label_13->setText(QApplication::translate("Score", "Jugada 2:", 0));
        label_14->setText(QApplication::translate("Score", "Jugada 1:", 0));
        label->setText(QApplication::translate("Score", "Puntos por jugada", 0));
        label_15->setText(QApplication::translate("Score", "Total:", 0));
        lb_total->setText(QString());
        lb_1->setText(QString());
        lb_coment->setText(QString());
        lb_2->setText(QString());
        lb_3->setText(QString());
        lb_4->setText(QString());
        lb_5->setText(QString());
        lb_6->setText(QString());
        lb_7->setText(QString());
        lb_8->setText(QString());
        lb_9->setText(QString());
        aceptar->setText(QApplication::translate("Score", "Aceptar", 0));
        lb_coment_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Score: public Ui_Score {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCORE_H
