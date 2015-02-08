#include "options.h"
#include "ui_options.h"
#include <mainwindow.h>

extern int op;


Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
    if (op==0){
        ui->rb1->setChecked(true);
    }
    if (op==1){
        ui->rb2->setChecked(true);
    }
    if (op==2){
        ui->rb3->setChecked(true);
    }
}

Options::~Options()
{
    delete ui;
}



void Options::on_aceptar_clicked()
{
    if (ui->rb1->isChecked()){op=0;}
    if (ui->rb2->isChecked()){op=1;}
    if (ui->rb3->isChecked()){op=2;}
    Options::close();
}
