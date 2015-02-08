#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <dialog.h>
#include <dialog2.h>
#include <dialog3.h>
#include <options.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_inicaJuego_clicked();
    void on_opt_clicked();


    void on_IniRap_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *game;
    Dialog2 *game2;
    Dialog3 *game3;

    Options *opt;
};

#endif // MAINWINDOW_H
