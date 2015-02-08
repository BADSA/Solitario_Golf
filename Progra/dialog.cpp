#include "dialog.h"
#include "ui_dialog.h"
#include "estructuras.h"
#include <score.h>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QSize>
#include <QMessageBox>
#include <QDebug>

//Variables para el control general del juego.
extern AStack<int> fila1;
extern AStack<int> fila2;
extern AStack<int> fila3;
extern AStack<int> fila4;
extern AStack<int> fila5;
extern AStack<int> fila6;
extern AStack<int> mazo;
extern AList<int> l1;
extern int descarte;
static QString path="./img/";
extern int puntos;
extern AList<int> puntoJugada;
extern int juego;
extern bool juegoRapido;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent, Qt::CustomizeWindowHint |
        Qt::WindowCloseButtonHint ),
    game(new Ui::Dialog)
{
    //Limpiar las pilas y lista.
    fila1.clear();
    fila2.clear();
    fila3.clear();
    fila4.clear();
    fila5.clear();
    fila6.clear();
    mazo.clear();
    l1.clear();
    descarte=0;

    //Inicializacion de ventana
    game->setupUi(this);
    //genera numeros para hacer shufle
    for (int j=1;j<53;j++){
        l1.append(j);
    }
    //shuffles de la lista
    l1.shuffle();
    l1.moveToStart();
    l1.shuffle();
    l1.moveToStart();
    l1.shuffle();
    //Ciclo para llenar el mazo
    for (l1.moveToEnd();l1.currPos()>=0;l1.prev()){
        mazo.push(l1.getValue());
        if (l1.currPos()==0)break;
    }
    //llenar las pilas
    for (int i=0;i<5;i++){
        fila1.push(mazo.pop());
    }

    //llenar las pilas
    for (int i=0;i<5;i++){
        fila2.push(mazo.pop());
    }
    //llenar las pilas
    for (int i=0;i<5;i++){
        fila3.push(mazo.pop());
    }
    //llenar las pilas
    for (int i=0;i<5;i++){
        fila4.push(mazo.pop());
    }
    //llenar las pilas
    for (int i=0;i<5;i++){
        fila5.push(mazo.pop());
    }
    //llenar las pilas
    for (int i=0;i<5;i++){
        fila6.push(mazo.pop());
    }

    l1.moveToStart();
    //Inicializacion de iconos para los botones
    game->b00->setIcon(QIcon(path+QString::number(l1.remove()))); game->b00->setIconSize(QSize(100,120));
    game->b01->setIcon(QIcon(path+QString::number(l1.remove()))); game->b01->setIconSize(QSize(100,120));
    game->b02->setIcon(QIcon(path+QString::number(l1.remove()))); game->b02->setIconSize(QSize(100,120));
    game->b03->setIcon(QIcon(path+QString::number(l1.remove()))); game->b03->setIconSize(QSize(100,120));
    game->b04->setIcon(QIcon(path+QString::number(l1.remove()))); game->b04->setIconSize(QSize(100,120));
    game->b10->setIcon(QIcon(path+QString::number(l1.remove()))); game->b10->setIconSize(QSize(100,120));
    game->b11->setIcon(QIcon(path+QString::number(l1.remove()))); game->b11->setIconSize(QSize(100,120));
    game->b12->setIcon(QIcon(path+QString::number(l1.remove()))); game->b12->setIconSize(QSize(100,120));
    game->b13->setIcon(QIcon(path+QString::number(l1.remove()))); game->b13->setIconSize(QSize(100,120));
    game->b14->setIcon(QIcon(path+QString::number(l1.remove()))); game->b14->setIconSize(QSize(100,120));
    game->b20->setIcon(QIcon(path+QString::number(l1.remove()))); game->b20->setIconSize(QSize(100,120));
    game->b21->setIcon(QIcon(path+QString::number(l1.remove()))); game->b21->setIconSize(QSize(100,120));
    game->b22->setIcon(QIcon(path+QString::number(l1.remove()))); game->b22->setIconSize(QSize(100,120));
    game->b23->setIcon(QIcon(path+QString::number(l1.remove()))); game->b23->setIconSize(QSize(100,120));
    game->b24->setIcon(QIcon(path+QString::number(l1.remove()))); game->b24->setIconSize(QSize(100,120));
    game->b30->setIcon(QIcon(path+QString::number(l1.remove()))); game->b30->setIconSize(QSize(100,120));
    game->b31->setIcon(QIcon(path+QString::number(l1.remove()))); game->b31->setIconSize(QSize(100,120));
    game->b32->setIcon(QIcon(path+QString::number(l1.remove()))); game->b32->setIconSize(QSize(100,120));
    game->b33->setIcon(QIcon(path+QString::number(l1.remove()))); game->b33->setIconSize(QSize(100,120));
    game->b34->setIcon(QIcon(path+QString::number(l1.remove()))); game->b34->setIconSize(QSize(100,120));
    game->b40->setIcon(QIcon(path+QString::number(l1.remove()))); game->b40->setIconSize(QSize(100,120));
    game->b41->setIcon(QIcon(path+QString::number(l1.remove()))); game->b41->setIconSize(QSize(100,120));
    game->b42->setIcon(QIcon(path+QString::number(l1.remove()))); game->b42->setIconSize(QSize(100,120));
    game->b43->setIcon(QIcon(path+QString::number(l1.remove()))); game->b43->setIconSize(QSize(100,120));
    game->b44->setIcon(QIcon(path+QString::number(l1.remove()))); game->b44->setIconSize(QSize(100,120));
    game->b50->setIcon(QIcon(path+QString::number(l1.remove()))); game->b50->setIconSize(QSize(100,120));
    game->b51->setIcon(QIcon(path+QString::number(l1.remove()))); game->b51->setIconSize(QSize(100,120));
    game->b52->setIcon(QIcon(path+QString::number(l1.remove()))); game->b52->setIconSize(QSize(100,120));
    game->b53->setIcon(QIcon(path+QString::number(l1.remove()))); game->b53->setIconSize(QSize(100,120));
    game->b54->setIcon(QIcon(path+QString::number(l1.remove()))); game->b54->setIconSize(QSize(100,120));
    game->m1->setIcon(QIcon(path+"volteada")); game->m1->setIconSize(QSize(100,120));
    game->m2->setIcon(QIcon(path+"volteada")); game->m2->setIconSize(QSize(100,120));
    game->m3->setIcon(QIcon(path+"volteada")); game->m3->setIconSize(QSize(100,120));
    game->m4->setIcon(QIcon(path+"volteada")); game->m4->setIconSize(QSize(100,120));
    game->m5->setIcon(QIcon(path+"volteada")); game->m5->setIconSize(QSize(100,120));
    game->m6->setIcon(QIcon(path+"volteada")); game->m6->setIconSize(QSize(100,120));
    game->m7->setIcon(QIcon(path+"volteada")); game->m7->setIconSize(QSize(100,120));
    game->m8->setIcon(QIcon(path+"volteada")); game->m8->setIconSize(QSize(100,120));
    game->m9->setIcon(QIcon(path+"volteada")); game->m9->setIconSize(QSize(100,120));
    game->m10->setIcon(QIcon(path+"volteada")); game->m10->setIconSize(QSize(100,120));
    game->m11->setIcon(QIcon(path+"volteada")); game->m11->setIconSize(QSize(100,120));
    game->m12->setIcon(QIcon(path+"volteada")); game->m12->setIconSize(QSize(100,120));
    game->m13->setIcon(QIcon(path+"volteada")); game->m13->setIconSize(QSize(100,120));
    game->m14->setIcon(QIcon(path+"volteada")); game->m14->setIconSize(QSize(100,120));
    game->m15->setIcon(QIcon(path+"volteada")); game->m15->setIconSize(QSize(100,120));
    game->m16->setIcon(QIcon(path+"volteada")); game->m16->setIconSize(QSize(100,120));
    game->m17->setIcon(QIcon(path+"volteada")); game->m17->setIconSize(QSize(100,120));
    game->m18->setIcon(QIcon(path+"volteada")); game->m18->setIconSize(QSize(100,120));
    game->m19->setIcon(QIcon(path+"volteada")); game->m19->setIconSize(QSize(100,120));
    game->m20->setIcon(QIcon(path+"volteada")); game->m20->setIconSize(QSize(100,120));
    game->m21->setIcon(QIcon(path+"volteada")); game->m21->setIconSize(QSize(100,120));
    game->m22->setIcon(QIcon(path+"volteada")); game->m22->setIconSize(QSize(100,120));
    game->descarte->setIconSize(QSize(100,120));
}
Dialog::~Dialog()
{
    delete game;
}
//Retorna el valor de la suma de las filas que se utiliza en diferentes funciones.
int Dialog::sumaFilas(){
    int result = fila1.length()+
            fila2.length()+
            fila3.length()+
            fila4.length()+
            fila5.length()+
            fila6.length();
    return result;
}

//Funcion revisa si hay una posible jugada o si se acaba el Juego
bool Dialog::revisaJuego(){
    if (mazo.length()==0){
        if (fila1.length()!=0){
            if (revisaJugada6())return false;
        }
        if (fila2.length()!=0){
            if (revisaJugada5())return false;
        }
        if (fila3.length()!=0){
            if (revisaJugada4())return false;
        }
        if (fila4.length()!=0){
            if (revisaJugada3())return false;
        }
        if (fila5.length()!=0){
            if (revisaJugada2())return false;
        }
        if (fila6.length()!=0){
            if (revisaJugada1())return false;
        }
        return true;
    }else{
        if (sumaFilas()==0){
            return true;
        }
    }
    return false;
}

/*
 *Funcion que relaiza la finalizacion del juego
 *revisa la condiciones del tipo de juego que se encuentra
 *muestra un msg para seguir a la siguiente ronda.
 */
void Dialog::finJuego(){
    if (juegoRapido){
        QMessageBox *msgBox = new QMessageBox(this);
                msgBox->setStyleSheet(NULL);
                msgBox->setWindowTitle("Fin de la Partida Rapida");
                msgBox->setText("La partida rapida ha finalizado su puntuacion fue de: "+QString::number(sumaFilas()-mazo.length()));
                msgBox->setWindowModality(Qt::NonModal);
                msgBox->setInformativeText("Sigue Jugando");
                msgBox->setStandardButtons(QMessageBox::Ok);
                msgBox->setButtonText(QMessageBox::Ok,"Aceptar");
                msgBox->exec();
                Dialog::close();
    }else{
        puntoJugada.append(sumaFilas()-mazo.length());
        if (juego<9){
            QMessageBox *msgBox = new QMessageBox(this);
                msgBox->setStyleSheet(NULL);
                msgBox->setWindowTitle("Fin de la Jugada");
                msgBox->setText("La Jugada ha finalizado con una puntuacion de: "+QString::number(sumaFilas()-mazo.length())+"puntos.");
                msgBox->setWindowModality(Qt::NonModal);
                msgBox->setInformativeText("La siguiente Jugada esta por comenzar.");
                msgBox->setStandardButtons(QMessageBox::Ok);
                msgBox->setButtonText(QMessageBox::Ok,"Continuar");
                msgBox->exec();
                Dialog::close();
       }else{
             scor = new Score(this);
             scor->exec();
             juego=0;
             Dialog::close();
        }

    }

}

//Funciones independientes para cada jugada segun la fila y el descarte.
//Se revisa si el nuero de descarte con el valor de la pila seleccionada
//es mayor o menor en 1. Modulo 13 para poder tener mejor manejo de los numeros
bool Dialog::revisaJugada1(){
   if ((((descarte%13)==(fila6.topValue()+1)%13 )
        || ((descarte%13)==((fila6.topValue()-1)%13)))
           &&((descarte%13!=0)
              &&(fila6.topValue()%13+descarte%13!=1))){
       return true;
   }
   else{
       return false;
   }
}
bool Dialog::revisaJugada2(){
   if ((((descarte%13)==(fila5.topValue()+1)%13 )
        || ((descarte%13)==((fila5.topValue()-1)%13)))
           &&((descarte%13!=0)
              &&(fila5.topValue()%13+descarte%13!=1))){
       return true;
   }
   else{
       return false;
   }
}
bool Dialog::revisaJugada3(){
   if ((((descarte%13)==(fila4.topValue()+1)%13 )
        || ((descarte%13)==((fila4.topValue()-1)%13)))
           &&((descarte%13!=0)
              &&(fila4.topValue()%13+descarte%13!=1))){
       return true;
   }
   else{
       return false;
   }
}
bool Dialog::revisaJugada4(){
   if ((((descarte%13)==(fila3.topValue()+1)%13 )
        || ((descarte%13)==((fila3.topValue()-1)%13)))
           &&((descarte%13!=0)
              &&(fila3.topValue()%13+descarte%13!=1))){
       return true;
   }
   else{
       return false;
   }
}
bool Dialog::revisaJugada5(){
   if ((((descarte%13)==(fila2.topValue()+1)%13 )
        || ((descarte%13)==((fila2.topValue()-1)%13)))
           &&((descarte%13!=0)
              &&(fila2.topValue()%13+descarte%13!=1))){
       return true;
   }
   else{
       return false;
   }
}
bool Dialog::revisaJugada6(){
    if ((((descarte%13)==(fila1.topValue()+1)%13 )
         || ((descarte%13)==((fila1.topValue()-1)%13)))
            &&((descarte%13!=0)
               &&(fila1.topValue()%13+descarte%13!=1))){
       return true;
   }
   else{
       return false;
   }
}
/*Acciones para cada boton en la ventana
Los botones fueron nombrados como si fuese una matriz el primer numero
corresponde a la columna y el segundo a la fila, cada boton realiza
las mismas accones las cuales son:
Descartar una carta de la pila y ponerla en el descarte de ser posible
descativar la visibilidad del mismo y mostrar como abilitado el boton
que se encuentra al lado de arriba de el.

Solamente el boton con teminacion 0 solo quita la visibilida ya que no
botones que abilitar en la parte superior o la pila es igual a cero.
*/
void Dialog::on_b54_clicked()
{   if (descarte==0){
        descarte=fila6.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b53->setEnabled(true);
        game->b54->setEnabled(false);
        game->b54->setVisible(false);

    }else{
        if (revisaJugada1()){
            descarte=fila6.pop();
            game->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game->b53->setEnabled(true);
            game->b54->setEnabled(false);
            game->b54->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();
        }
    }
}
void Dialog::on_b53_clicked()
{
    if (revisaJugada1()){
        descarte=fila6.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b52->setEnabled(true);
        game->b53->setEnabled(false);
        game->b53->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }

}
void Dialog::on_b52_clicked()
{
    if (revisaJugada1()){
        descarte=fila6.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b51->setEnabled(true);
        game->b52->setEnabled(false);
        game->b52->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog::on_b51_clicked()
{
    if (revisaJugada1()){
        descarte=fila6.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b50->setEnabled(true);
        game->b51->setEnabled(false);
        game->b51->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog::on_b50_clicked()
{
    if (revisaJugada1()){
        descarte=fila6.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b50->setEnabled(false);
        game->b50->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }
}

void Dialog::on_b44_clicked()
{
    if (descarte==0){
       descarte=fila5.pop();
       game->descarte->setIcon(QIcon(path+QString::number(descarte)));
       game->b43->setEnabled(true);
       game->b44->setEnabled(false);
       game->b44->setVisible(false);
    }else{
        if (revisaJugada2()){
            descarte=fila5.pop();
            game->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game->b43->setEnabled(true);
            game->b44->setEnabled(false);
            game->b44->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();
        }
    }
}

void Dialog::on_b43_clicked()
{
    if (revisaJugada2()){
        descarte=fila5.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b42->setEnabled(true);
        game->b43->setEnabled(false);
        game->b43->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }
}
void Dialog::on_b42_clicked()
{
    if (revisaJugada2()){
        descarte=fila5.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b41->setEnabled(true);
        game->b42->setEnabled(false);
        game->b42->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }
}

void Dialog::on_b41_clicked()
{
    if (revisaJugada2()){
        descarte=fila5.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b40->setEnabled(true);
        game->b41->setEnabled(false);
        game->b41->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}

void Dialog::on_b40_clicked()
{
    if (revisaJugada2()){
        descarte=fila5.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b40->setEnabled(false);
        game->b40->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog::on_b34_clicked()
{
    if (descarte==0){
       descarte=fila4.pop();
       game->descarte->setIcon(QIcon(path+QString::number(descarte)));
       game->b33->setEnabled(true);
       game->b34->setEnabled(false);
       game->b34->setVisible(false);
    }else{
        if (revisaJugada3()){
            descarte=fila4.pop();
            game->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game->b33->setEnabled(true);
            game->b34->setEnabled(false);
            game->b34->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();

        }
    }

}
void Dialog::on_b33_clicked()
{
    if (revisaJugada3()){
        descarte=fila4.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b32->setEnabled(true);
        game->b33->setEnabled(false);
        game->b33->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog::on_b32_clicked()
{
    if (revisaJugada3()){
        descarte=fila4.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b31->setEnabled(true);
        game->b32->setEnabled(false);
        game->b32->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog::on_b31_clicked()
{
    if (revisaJugada3()){
        descarte=fila4.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b30->setEnabled(true);
        game->b31->setEnabled(false);
        game->b31->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}

void Dialog::on_b30_clicked()
{
    if (revisaJugada3()){
        descarte=fila4.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b30->setEnabled(false);
        game->b30->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog::on_b24_clicked()
{
    if (descarte==0){
       descarte=fila3.pop();
       game->descarte->setIcon(QIcon(path+QString::number(descarte)));
       game->b23->setEnabled(true);
       game->b24->setEnabled(false);
       game->b24->setVisible(false);

    }else{
        if (revisaJugada4()){
            descarte=fila3.pop();
            game->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game->b23->setEnabled(true);
            game->b24->setEnabled(false);
            game->b24->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();

        }
    }

}
void Dialog::on_b23_clicked()
{
    if (revisaJugada4()){
        descarte=fila3.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b22->setEnabled(true);
        game->b23->setEnabled(false);
        game->b23->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog::on_b22_clicked()
{
    if (revisaJugada4()){
        descarte=fila3.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b21->setEnabled(true);
        game->b22->setEnabled(false);
        game->b22->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog::on_b21_clicked()
{
    if (revisaJugada4()){
        descarte=fila3.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b20->setEnabled(true);
        game->b21->setEnabled(false);
        game->b21->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog::on_b20_clicked()
{
    if (revisaJugada4()){
        descarte=fila3.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b20->setEnabled(false);
        game->b20->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}

void Dialog::on_b14_clicked()
{
    if (descarte==0){
       descarte=fila2.pop();
       game->descarte->setIcon(QIcon(path+QString::number(descarte)));
       game->b13->setEnabled(true);
       game->b14->setEnabled(false);
       game->b14->setVisible(false);
    }else{
        if (revisaJugada5()){
            descarte=fila2.pop();
            game->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game->b13->setEnabled(true);
            game->b14->setEnabled(false);
            game->b14->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();
        }
    }
}
void Dialog::on_b13_clicked()
{
    if (revisaJugada5()){
        descarte=fila2.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b12->setEnabled(true);
        game->b13->setEnabled(false);
        game->b13->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog::on_b12_clicked()
{
    if (revisaJugada5()){
        descarte=fila2.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b11->setEnabled(true);
        game->b12->setEnabled(false);
        game->b12->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog::on_b11_clicked()
{
    if (revisaJugada5()){
        descarte=fila2.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b10->setEnabled(true);
        game->b11->setEnabled(false);
        game->b11->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog::on_b10_clicked()
{
    if (revisaJugada5()){
        descarte=fila2.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b10->setEnabled(false);
        game->b10->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog::on_b04_clicked()
{
    if (descarte==0){
       descarte=fila1.pop();
       game->descarte->setIcon(QIcon(path+QString::number(descarte)));
       game->b03->setEnabled(true);
       game->b04->setEnabled(false);
       game->b04->setVisible(false);
    }else{
        if (revisaJugada6()){
            descarte=fila1.pop();
            game->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game->b03->setEnabled(true);
            game->b04->setEnabled(false);
            game->b04->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();
        }
    }
}
void Dialog::on_b03_clicked()
{
    if (revisaJugada6()){
        descarte=fila1.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b02->setEnabled(true);
        game->b03->setEnabled(false);
        game->b03->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }
}
void Dialog::on_b02_clicked()
{
    if (revisaJugada6()){
        descarte=fila1.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b01->setEnabled(true);
        game->b02->setEnabled(false);
        game->b02->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }
}
void Dialog::on_b01_clicked()
{
    if (revisaJugada6()){
        descarte=fila1.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b00->setEnabled(true);
        game->b01->setEnabled(false);
        game->b01->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }
}
void Dialog::on_b00_clicked()
{
    if (revisaJugada6()){
        descarte=fila1.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->b00->setEnabled(false);
        game->b00->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }
}

void Dialog::on_m1_clicked()
{   if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m1->setVisible(false);
        game->m2->setEnabled(true);
   }
}

void Dialog::on_m2_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m2->setVisible(false);
        game->m3->setEnabled(true);
    }
}
void Dialog::on_m3_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m3->setVisible(false);
        game->m4->setEnabled(true);
       }
}
void Dialog::on_m4_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m4->setVisible(false);
        game->m5->setEnabled(true);
       }
}
void Dialog::on_m5_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m5->setVisible(false);
        game->m6->setEnabled(true);
       }
}
void Dialog::on_m6_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m6->setVisible(false);
        game->m7->setEnabled(true);
       }
}
void Dialog::on_m7_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m7->setVisible(false);
        game->m8->setEnabled(true);
       }
}
void Dialog::on_m8_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m8->setVisible(false);
        game->m9->setEnabled(true);
       }
}
void Dialog::on_m9_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m9->setVisible(false);
        game->m10->setEnabled(true);
       }
}
void Dialog::on_m10_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m10->setVisible(false);
        game->m11->setEnabled(true);
       }
}
void Dialog::on_m11_clicked()
{
    if (mazo.length()!=0){
            descarte=mazo.pop();
            game->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game->m11->setVisible(false);
            game->m12->setEnabled(true);
            }
    }
void Dialog::on_m12_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m12->setVisible(false);
        game->m13->setEnabled(true);
       }
}
void Dialog::on_m13_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m13->setVisible(false);
        game->m14->setEnabled(true);
       }
}
void Dialog::on_m14_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m14->setVisible(false);
        game->m15->setEnabled(true);
    }
}
void Dialog::on_m15_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m15->setVisible(false);
        game->m16->setEnabled(true);
    }
}
void Dialog::on_m16_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m16->setVisible(false);
        game->m17->setEnabled(true);
    }
}
void Dialog::on_m17_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m17->setVisible(false);
        game->m18->setEnabled(true);
    }
}
void Dialog::on_m18_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m18->setVisible(false);
        game->m19->setEnabled(true);
    }
}
void Dialog::on_m19_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m19->setVisible(false);
        game->m20->setEnabled(true);
    }
}
void Dialog::on_m20_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m20->setVisible(false);
        game->m21->setEnabled(true);
    }
}
void Dialog::on_m21_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m21->setVisible(false);
        game->m22->setEnabled(true);
        if (revisaJuego()){

        }
    }
}
void Dialog::on_m22_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game->m22->setVisible(false);
       // std::cout<<mazo.length();
    }
    //std::cout<<mazo.length()<<std::endl;
    if (revisaJuego()){
        finJuego();
    }
}
void Dialog::on_leave_clicked()
{
    QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setStyleSheet(NULL);
            msgBox->setWindowTitle("Abandonar el Juego :(");
            msgBox->setText(QString::fromUtf8("Si abandona el juego perderá todo el progreso realizado."));
            msgBox->setWindowModality(Qt::NonModal);
            msgBox->setInformativeText(QString::fromUtf8("¿Seguro que desea abandonar la partida?"));
            msgBox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox->setButtonText(QMessageBox::Yes,"Si");
            msgBox->setButtonText(QMessageBox::No,"No");
            msgBox->setDefaultButton(QMessageBox::No);
            //Cierra ventana si la respuesta es si
            if (msgBox->exec()==QMessageBox::Yes){
                //Dialog::destruyeVariables();
                juego=10;
                Dialog::close();
            }
}
