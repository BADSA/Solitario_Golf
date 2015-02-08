#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDir>
#include <dialog.h>
#include <iostream>
#include <QString>
#include <options.h>
#include <QMessageBox>



extern int juego;
extern int op;
extern bool juegoRapido;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    juego=1;
    op=0;

}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_inicaJuego_clicked()
{
    std::cout<<juego<<std::endl;
    switch (op){
    case 0:
        if (juego <10){
            game = new Dialog(this);
            game->setWindowTitle("Solitario Golf-Jugada "+QString::number(juego));
            game->exec();
            game->close();
            juego++;
            if (juego<10){
                ui->inicaJuego->animateClick(100);
            }
        }else{
            juego=1;
        }
        break;
    case 1:
        if (juego <10){
            game2 = new Dialog2(this);
            game2->setWindowTitle("Solitario Golf-Jugada "+QString::number(juego));
            game2->show();
            game2->raise();
            game2->activateWindow();
            game2->exec();
            if (juego<10){
                ui->inicaJuego->animateClick(100);
            }
            juego++;
        }else{
            juego=1;
        }
        break;

    default:
        if (juego <=9){
            game3 = new Dialog3(this);
            game3->setWindowTitle("Solitario Golf-Jugada "+QString::number(juego));
            game3->show();
            game3->raise();
            game3->activateWindow();
            game3->exec();
            if (juego<10){
                ui->inicaJuego->animateClick(100);
            }
            juego++;
        }else{
            juego=1;
        }
        break;
    }
}

void MainWindow::on_opt_clicked(){
    opt=new Options(this);
    opt->exec();
}

void MainWindow::on_IniRap_clicked()
{   juego=1;
    switch (op){
    case 0:
        juegoRapido=true;
        game = new Dialog(this);
        game->setWindowTitle("Solitario Golf-Juego Rapido");
        game->show();
        game->raise();
        game->activateWindow();
        game->exec();
        juegoRapido=false;
        break;
    case 1:
        juegoRapido=true;
        game2 = new Dialog2(this);
        game2->setWindowTitle("Solitario Golf-Juego Rapido-Tipo: Q sobre K.");
        game2->show();
        game2->raise();
        game2->activateWindow();
        game2->exec();
        juegoRapido=false;
        break;
    default:
        juegoRapido=true;
        game3 = new Dialog3(this);
        game3->setWindowTitle("Solitario Golf-Juego Rapido- Modo: Q sobre K, A sobre K.");
        game3->show();
        game3->raise();
        game3->activateWindow();
        game3->exec();
        juegoRapido=false;
        break;
    }
}
