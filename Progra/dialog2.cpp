#include "dialog2.h"
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

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent, Qt::CustomizeWindowHint |
        Qt::WindowCloseButtonHint ),
    game2(new Ui::Dialog)
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
    game2->setupUi(this);
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
    game2->b00->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b00->setIconSize(QSize(100,120));
    game2->b01->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b01->setIconSize(QSize(100,120));
    game2->b02->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b02->setIconSize(QSize(100,120));
    game2->b03->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b03->setIconSize(QSize(100,120));
    game2->b04->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b04->setIconSize(QSize(100,120));
    game2->b10->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b10->setIconSize(QSize(100,120));
    game2->b11->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b11->setIconSize(QSize(100,120));
    game2->b12->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b12->setIconSize(QSize(100,120));
    game2->b13->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b13->setIconSize(QSize(100,120));
    game2->b14->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b14->setIconSize(QSize(100,120));
    game2->b20->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b20->setIconSize(QSize(100,120));
    game2->b21->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b21->setIconSize(QSize(100,120));
    game2->b22->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b22->setIconSize(QSize(100,120));
    game2->b23->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b23->setIconSize(QSize(100,120));
    game2->b24->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b24->setIconSize(QSize(100,120));
    game2->b30->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b30->setIconSize(QSize(100,120));
    game2->b31->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b31->setIconSize(QSize(100,120));
    game2->b32->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b32->setIconSize(QSize(100,120));
    game2->b33->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b33->setIconSize(QSize(100,120));
    game2->b34->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b34->setIconSize(QSize(100,120));
    game2->b40->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b40->setIconSize(QSize(100,120));
    game2->b41->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b41->setIconSize(QSize(100,120));
    game2->b42->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b42->setIconSize(QSize(100,120));
    game2->b43->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b43->setIconSize(QSize(100,120));
    game2->b44->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b44->setIconSize(QSize(100,120));
    game2->b50->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b50->setIconSize(QSize(100,120));
    game2->b51->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b51->setIconSize(QSize(100,120));
    game2->b52->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b52->setIconSize(QSize(100,120));
    game2->b53->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b53->setIconSize(QSize(100,120));
    game2->b54->setIcon(QIcon(path+QString::number(l1.remove()))); game2->b54->setIconSize(QSize(100,120));
    game2->m1->setIcon(QIcon(path+"volteada")); game2->m1->setIconSize(QSize(100,120));
    game2->m2->setIcon(QIcon(path+"volteada")); game2->m2->setIconSize(QSize(100,120));
    game2->m3->setIcon(QIcon(path+"volteada")); game2->m3->setIconSize(QSize(100,120));
    game2->m4->setIcon(QIcon(path+"volteada")); game2->m4->setIconSize(QSize(100,120));
    game2->m5->setIcon(QIcon(path+"volteada")); game2->m5->setIconSize(QSize(100,120));
    game2->m6->setIcon(QIcon(path+"volteada")); game2->m6->setIconSize(QSize(100,120));
    game2->m7->setIcon(QIcon(path+"volteada")); game2->m7->setIconSize(QSize(100,120));
    game2->m8->setIcon(QIcon(path+"volteada")); game2->m8->setIconSize(QSize(100,120));
    game2->m9->setIcon(QIcon(path+"volteada")); game2->m9->setIconSize(QSize(100,120));
    game2->m10->setIcon(QIcon(path+"volteada")); game2->m10->setIconSize(QSize(100,120));
    game2->m11->setIcon(QIcon(path+"volteada")); game2->m11->setIconSize(QSize(100,120));
    game2->m12->setIcon(QIcon(path+"volteada")); game2->m12->setIconSize(QSize(100,120));
    game2->m13->setIcon(QIcon(path+"volteada")); game2->m13->setIconSize(QSize(100,120));
    game2->m14->setIcon(QIcon(path+"volteada")); game2->m14->setIconSize(QSize(100,120));
    game2->m15->setIcon(QIcon(path+"volteada")); game2->m15->setIconSize(QSize(100,120));
    game2->m16->setIcon(QIcon(path+"volteada")); game2->m16->setIconSize(QSize(100,120));
    game2->m17->setIcon(QIcon(path+"volteada")); game2->m17->setIconSize(QSize(100,120));
    game2->m18->setIcon(QIcon(path+"volteada")); game2->m18->setIconSize(QSize(100,120));
    game2->m19->setIcon(QIcon(path+"volteada")); game2->m19->setIconSize(QSize(100,120));
    game2->m20->setIcon(QIcon(path+"volteada")); game2->m20->setIconSize(QSize(100,120));
    game2->m21->setIcon(QIcon(path+"volteada")); game2->m21->setIconSize(QSize(100,120));
    game2->m22->setIcon(QIcon(path+"volteada")); game2->m22->setIconSize(QSize(100,120));
    game2->descarte->setIconSize(QSize(100,120));
}
Dialog2::~Dialog2()
{
    delete game2;
}
//Retorna el valor de la suma de las filas que se utiliza en diferentes funciones.
int Dialog2::sumaFilas(){
    int result = fila1.length()+
            fila2.length()+
            fila3.length()+
            fila4.length()+
            fila5.length()+
            fila6.length();
    return result;
}

//Funcion revisa si hay una posible jugada o si se acaba el Juego
bool Dialog2::revisaJuego(){
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
void Dialog2::finJuego(){
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
            Dialog2::close();
    }else{
        puntoJugada.append(sumaFilas()-mazo.length());
        if (juego<9){
            QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setStyleSheet(NULL);
            msgBox->setWindowTitle("Fin de la Jugada");
            msgBox->setText("La Jugada ha finalizado con una puntuacion de: "+QString::number(sumaFilas()-mazo.length())+" puntos.");
            msgBox->setWindowModality(Qt::NonModal);
            msgBox->setInformativeText("La siguiente Jugada esta por comenzar.");
            msgBox->setStandardButtons(QMessageBox::Ok);
            msgBox->setButtonText(QMessageBox::Ok,"Continuar");
            msgBox->exec();
            Dialog2::close();
       }else{
             scor = new Score(this);
             scor->exec();
             juego=0;
             Dialog2::close();
        }

    }

}

//Funciones independientes para cada jugada segun la fila y el descarte.
//Se revisa si el nuero de descarte con el valor de la pila seleccionada
//es mayor o menor en 1. Modulo 13 para poder tener mejor manejo de los numeros
bool Dialog2::revisaJugada1(){
   if ((((descarte%13)==(fila6.topValue()+1)%13 )
        || ((descarte%13)==((fila6.topValue()-1)%13)))
              &&(fila6.topValue()%13+descarte%13!=1)){
       return true;
   }
   else{
       return false;
   }
}
bool Dialog2::revisaJugada2(){
   if ((((descarte%13)==(fila5.topValue()+1)%13 )
        || ((descarte%13)==((fila5.topValue()-1)%13)))
              &&(fila5.topValue()%13+descarte%13!=1)){
       return true;
   }
   else{
       return false;
   }
}
bool Dialog2::revisaJugada3(){
   if ((((descarte%13)==(fila4.topValue()+1)%13 )
        || ((descarte%13)==((fila4.topValue()-1)%13)))
              &&(fila4.topValue()%13+descarte%13!=1)){
       return true;
   }
   else{
       return false;
   }
}
bool Dialog2::revisaJugada4(){
   if ((((descarte%13)==(fila3.topValue()+1)%13 )
        || ((descarte%13)==((fila3.topValue()-1)%13)))
              &&(fila3.topValue()%13+descarte%13!=1)){
       return true;
   }
   else{
       return false;
   }
}
bool Dialog2::revisaJugada5(){
   if ((((descarte%13)==(fila2.topValue()+1)%13 )
        || ((descarte%13)==((fila2.topValue()-1)%13)))
              &&(fila2.topValue()%13+descarte%13!=1)){
       return true;
   }
   else{
       return false;
   }
}
bool Dialog2::revisaJugada6(){
    if ((((descarte%13)==(fila1.topValue()+1)%13 )
         || ((descarte%13)==((fila1.topValue()-1)%13)))
               &&(fila1.topValue()%13+descarte%13!=1)){
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
void Dialog2::on_b54_clicked()
{   if (descarte==0){
        descarte=fila6.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b53->setEnabled(true);
        game2->b54->setEnabled(false);
        game2->b54->setVisible(false);

    }else{
        if (revisaJugada1()){
            descarte=fila6.pop();
            game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game2->b53->setEnabled(true);
            game2->b54->setEnabled(false);
            game2->b54->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();
        }
    }
}
void Dialog2::on_b53_clicked()
{
    if (revisaJugada1()){
        descarte=fila6.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b52->setEnabled(true);
        game2->b53->setEnabled(false);
        game2->b53->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }

}
void Dialog2::on_b52_clicked()
{
    if (revisaJugada1()){
        descarte=fila6.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b51->setEnabled(true);
        game2->b52->setEnabled(false);
        game2->b52->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog2::on_b51_clicked()
{
    if (revisaJugada1()){
        descarte=fila6.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b50->setEnabled(true);
        game2->b51->setEnabled(false);
        game2->b51->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog2::on_b50_clicked()
{
    if (revisaJugada1()){
        descarte=fila6.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b50->setEnabled(false);
        game2->b50->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }
}

void Dialog2::on_b44_clicked()
{
    if (descarte==0){
       descarte=fila5.pop();
       game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
       game2->b43->setEnabled(true);
       game2->b44->setEnabled(false);
       game2->b44->setVisible(false);
    }else{
        if (revisaJugada2()){
            descarte=fila5.pop();
            game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game2->b43->setEnabled(true);
            game2->b44->setEnabled(false);
            game2->b44->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();
        }
    }
}

void Dialog2::on_b43_clicked()
{
    if (revisaJugada2()){
        descarte=fila5.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b42->setEnabled(true);
        game2->b43->setEnabled(false);
        game2->b43->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }
}
void Dialog2::on_b42_clicked()
{
    if (revisaJugada2()){
        descarte=fila5.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b41->setEnabled(true);
        game2->b42->setEnabled(false);
        game2->b42->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }
}

void Dialog2::on_b41_clicked()
{
    if (revisaJugada2()){
        descarte=fila5.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b40->setEnabled(true);
        game2->b41->setEnabled(false);
        game2->b41->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}

void Dialog2::on_b40_clicked()
{
    if (revisaJugada2()){
        descarte=fila5.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b40->setEnabled(false);
        game2->b40->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog2::on_b34_clicked()
{
    if (descarte==0){
       descarte=fila4.pop();
       game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
       game2->b33->setEnabled(true);
       game2->b34->setEnabled(false);
       game2->b34->setVisible(false);
    }else{
        if (revisaJugada3()){
            descarte=fila4.pop();
            game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game2->b33->setEnabled(true);
            game2->b34->setEnabled(false);
            game2->b34->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();

        }
    }

}
void Dialog2::on_b33_clicked()
{
    if (revisaJugada3()){
        descarte=fila4.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b32->setEnabled(true);
        game2->b33->setEnabled(false);
        game2->b33->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog2::on_b32_clicked()
{
    if (revisaJugada3()){
        descarte=fila4.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b31->setEnabled(true);
        game2->b32->setEnabled(false);
        game2->b32->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog2::on_b31_clicked()
{
    if (revisaJugada3()){
        descarte=fila4.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b30->setEnabled(true);
        game2->b31->setEnabled(false);
        game2->b31->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}

void Dialog2::on_b30_clicked()
{
    if (revisaJugada3()){
        descarte=fila4.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b30->setEnabled(false);
        game2->b30->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog2::on_b24_clicked()
{
    if (descarte==0){
       descarte=fila3.pop();
       game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
       game2->b23->setEnabled(true);
       game2->b24->setEnabled(false);
       game2->b24->setVisible(false);

    }else{
        if (revisaJugada4()){
            descarte=fila3.pop();
            game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game2->b23->setEnabled(true);
            game2->b24->setEnabled(false);
            game2->b24->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();

        }
    }

}
void Dialog2::on_b23_clicked()
{
    if (revisaJugada4()){
        descarte=fila3.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b22->setEnabled(true);
        game2->b23->setEnabled(false);
        game2->b23->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog2::on_b22_clicked()
{
    if (revisaJugada4()){
        descarte=fila3.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b21->setEnabled(true);
        game2->b22->setEnabled(false);
        game2->b22->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog2::on_b21_clicked()
{
    if (revisaJugada4()){
        descarte=fila3.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b20->setEnabled(true);
        game2->b21->setEnabled(false);
        game2->b21->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog2::on_b20_clicked()
{
    if (revisaJugada4()){
        descarte=fila3.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b20->setEnabled(false);
        game2->b20->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}

void Dialog2::on_b14_clicked()
{
    if (descarte==0){
       descarte=fila2.pop();
       game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
       game2->b13->setEnabled(true);
       game2->b14->setEnabled(false);
       game2->b14->setVisible(false);
    }else{
        if (revisaJugada5()){
            descarte=fila2.pop();
            game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game2->b13->setEnabled(true);
            game2->b14->setEnabled(false);
            game2->b14->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();
        }
    }

}
void Dialog2::on_b13_clicked()
{
    if (revisaJugada5()){
        descarte=fila2.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b12->setEnabled(true);
        game2->b13->setEnabled(false);
        game2->b13->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }

}
void Dialog2::on_b12_clicked()
{
    if (revisaJugada5()){
        descarte=fila2.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b11->setEnabled(true);
        game2->b12->setEnabled(false);
        game2->b12->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog2::on_b11_clicked()
{
    if (revisaJugada5()){
        descarte=fila2.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b10->setEnabled(true);
        game2->b11->setEnabled(false);
        game2->b11->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog2::on_b10_clicked()
{
    if (revisaJugada5()){
        descarte=fila2.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b10->setEnabled(false);
        game2->b10->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog2::on_b04_clicked()
{
    if (descarte==0){
       descarte=fila1.pop();
       game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
       game2->b03->setEnabled(true);
       game2->b04->setEnabled(false);
       game2->b04->setVisible(false);
    }else{
        if (revisaJugada6()){
            descarte=fila1.pop();
            game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game2->b03->setEnabled(true);
            game2->b04->setEnabled(false);
            game2->b04->setVisible(false);
        }
        if (revisaJuego()){
            finJuego();
        }
    }
}

void Dialog2::on_b03_clicked()
{
    if (revisaJugada6()){
        descarte=fila1.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b02->setEnabled(true);
        game2->b03->setEnabled(false);
        game2->b03->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog2::on_b02_clicked()
{
    if (revisaJugada6()){
        descarte=fila1.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b01->setEnabled(true);
        game2->b02->setEnabled(false);
        game2->b02->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog2::on_b01_clicked()
{
    if (revisaJugada6()){
        descarte=fila1.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b00->setEnabled(true);
        game2->b01->setEnabled(false);
        game2->b01->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();

    }
}
void Dialog2::on_b00_clicked()
{
    if (revisaJugada6()){
        descarte=fila1.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->b00->setEnabled(false);
        game2->b00->setVisible(false);
    }
    if (revisaJuego()){
        finJuego();
    }
}

void Dialog2::on_m1_clicked()
{   if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m1->setVisible(false);
        game2->m2->setEnabled(true);
   }
}

void Dialog2::on_m2_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m2->setVisible(false);
        game2->m3->setEnabled(true);
    }
}
void Dialog2::on_m3_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m3->setVisible(false);
        game2->m4->setEnabled(true);
       }
}
void Dialog2::on_m4_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m4->setVisible(false);
        game2->m5->setEnabled(true);
       }
}
void Dialog2::on_m5_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m5->setVisible(false);
        game2->m6->setEnabled(true);
       }
}
void Dialog2::on_m6_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m6->setVisible(false);
        game2->m7->setEnabled(true);
       }
}
void Dialog2::on_m7_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m7->setVisible(false);
        game2->m8->setEnabled(true);
       }
}
void Dialog2::on_m8_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m8->setVisible(false);
        game2->m9->setEnabled(true);
       }
}
void Dialog2::on_m9_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m9->setVisible(false);
        game2->m10->setEnabled(true);
       }
}
void Dialog2::on_m10_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m10->setVisible(false);
        game2->m11->setEnabled(true);
       }
}

void Dialog2::on_m11_clicked()
{
    if (mazo.length()!=0){
            descarte=mazo.pop();
            game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
            game2->m11->setVisible(false);
            game2->m12->setEnabled(true);
            }
    }

void Dialog2::on_m12_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m12->setVisible(false);
        game2->m13->setEnabled(true);
       }
}
void Dialog2::on_m13_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m13->setVisible(false);
        game2->m14->setEnabled(true);
       }
}
void Dialog2::on_m14_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m14->setVisible(false);
        game2->m15->setEnabled(true);
    }
}
void Dialog2::on_m15_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m15->setVisible(false);
        game2->m16->setEnabled(true);
    }
}
void Dialog2::on_m16_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m16->setVisible(false);
        game2->m17->setEnabled(true);
    }
}
void Dialog2::on_m17_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m17->setVisible(false);
        game2->m18->setEnabled(true);
    }
}
void Dialog2::on_m18_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m18->setVisible(false);
        game2->m19->setEnabled(true);
    }
}
void Dialog2::on_m19_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m19->setVisible(false);
        game2->m20->setEnabled(true);
    }
}
void Dialog2::on_m20_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m20->setVisible(false);
        game2->m21->setEnabled(true);
    }
}
void Dialog2::on_m21_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m21->setVisible(false);
        game2->m22->setEnabled(true);
        if (revisaJuego()){

        }
    }
}

void Dialog2::on_m22_clicked()
{
    if (mazo.length()!=0){
        descarte=mazo.pop();
        game2->descarte->setIcon(QIcon(path+QString::number(descarte)));
        game2->m22->setVisible(false);
       // std::cout<<mazo.length();
    }
    //std::cout<<mazo.length()<<std::endl;
    if (revisaJuego()){
        finJuego();
    }
}


void Dialog2::on_leave_clicked()
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
        //Dialog2::destruyeVariables();
        juego=10;
        Dialog2::close();
    }
}
