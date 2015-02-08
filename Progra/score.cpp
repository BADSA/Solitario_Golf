#include "score.h"
#include "ui_score.h"
#include <estructuras.h>
#include <QString>

extern AList<int> puntoJugada;

Score::Score(QWidget *parent) :
    QDialog(parent),
    scor(new Ui::Score)
{
    scor->setupUi(this);
    int total=0;
    for (puntoJugada.moveToStart();puntoJugada.currPos()<=9;puntoJugada.next()){
        total+=puntoJugada.getValue();
        if (puntoJugada.currPos()==0)break;
    }
    puntoJugada.moveToStart();
    scor->lb_1->setText(QString::number(puntoJugada.remove()));
    scor->lb_2->setText(QString::number(puntoJugada.remove()));
    scor->lb_3->setText(QString::number(puntoJugada.remove()));
    scor->lb_4->setText(QString::number(puntoJugada.remove()));
    scor->lb_5->setText(QString::number(puntoJugada.remove()));
    scor->lb_6->setText(QString::number(puntoJugada.remove()));
    scor->lb_7->setText(QString::number(puntoJugada.remove()));
    scor->lb_8->setText(QString::number(puntoJugada.remove()));
    scor->lb_9->setText(QString::number(puntoJugada.remove()));
    scor->lb_total->setText(QString::number(total));
    if (0<total && total<=45){
        scor->lb_coment->setText("Usted obtuvo un juego Par, excelente!");
        scor->lb_coment_2->setText("Sigue jugando y obten un juego Perfecto");
    }
    if (total>45){
        scor->lb_coment->setText("Usted obtuvo una puntuacion muy alta");
        scor->lb_coment_2->setText("Sigue jugando y obten un juego Par");
    }
    if (total<=0){
        scor->lb_coment->setText("Usted obtuvo un juego Perfecto, Felicidad!");
        scor->lb_coment_2->setText("You ROCK!!");
    }
}

Score::~Score()
{
    delete scor;
}
