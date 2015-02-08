#include "mainwindow.h"
#include <QApplication>
#include <estructuras.h>


int op;
int juego;
bool juegoRapido;
AStack<int> fila1(5);
AStack<int> fila2(5);
AStack<int> fila3(5);
AStack<int> fila4(5);
AStack<int> fila5(5);
AStack<int> fila6(5);
AStack<int> mazo(52);
AList<int> l1(52);
int descarte;
AList<int> puntoJugada(9);

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
