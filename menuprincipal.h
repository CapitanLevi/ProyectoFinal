#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#include <QMainWindow>
#include <QMediaPlayer>
#include <QMovie>
#include "about.h"

namespace Ui {
class MenuPrincipal;
}

class MenuPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuPrincipal(QWidget *parent = 0);
    ~MenuPrincipal();
    QMovie *movie;
    QMediaPlayer * music;
    int tamletra=25;
    About *about;

private slots:
    void on_singleplayer_clicked();
    void on_about_clicked();
    void on_multiplayer_clicked();
    void on_quit_clicked();

private:
    Ui::MenuPrincipal *ui;

};

#endif // MENUPRINCIPAL_H
