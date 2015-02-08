#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>
#include <score.h>

//String para el path de las imagenes


namespace Ui {
class Dialog;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog2(QWidget *parent = 0);
    ~Dialog2();


private slots:
    void on_b50_clicked();
    void on_b51_clicked();
    void on_b52_clicked();
    void on_b53_clicked();
    void on_b54_clicked();
    void on_b40_clicked();
    void on_b41_clicked();
    void on_b42_clicked();
    void on_b43_clicked();
    void on_b44_clicked();
    void on_b30_clicked();
    void on_b31_clicked();
    void on_b32_clicked();
    void on_b33_clicked();
    void on_b34_clicked();
    void on_b20_clicked();
    void on_b21_clicked();
    void on_b22_clicked();
    void on_b23_clicked();
    void on_b24_clicked();
    void on_b10_clicked();
    void on_b11_clicked();
    void on_b12_clicked();
    void on_b13_clicked();
    void on_b14_clicked();
    void on_b00_clicked();
    void on_b01_clicked();
    void on_b02_clicked();
    void on_b03_clicked();
    void on_b04_clicked();
    void on_m1_clicked();
    void on_m2_clicked();
    void on_m3_clicked();
    void on_m4_clicked();
    void on_m5_clicked();
    void on_m6_clicked();
    void on_m7_clicked();
    void on_m8_clicked();
    void on_m9_clicked();
    void on_m10_clicked();
    void on_m11_clicked();
    void on_m12_clicked();
    void on_m13_clicked();
    void on_m14_clicked();
    void on_m15_clicked();
    void on_m16_clicked();
    void on_m17_clicked();
    void on_m18_clicked();
    void on_m19_clicked();
    void on_m20_clicked();
    void on_m21_clicked();
    void on_m22_clicked();
    bool revisaJuego();
    bool revisaJugada1();
    bool revisaJugada2();
    bool revisaJugada3();
    bool revisaJugada4();
    bool revisaJugada5();
    bool revisaJugada6();
    int sumaFilas();
    void finJuego();
    void on_leave_clicked();

private:
    Ui::Dialog *game2;
    Score *scor;

};


#endif // DIALOG2_H
