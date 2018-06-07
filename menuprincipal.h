#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#include <QMainWindow>
#include <QMediaPlayer>

namespace Ui {
class MenuPrincipal;
}

class MenuPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuPrincipal(QWidget *parent = 0);
    ~MenuPrincipal();

    QMediaPlayer * music;

private slots:
    void on_singleplayer_clicked();

    void on_about_clicked();

    void on_multiplayer_clicked();

private:
    Ui::MenuPrincipal *ui;
};

#endif // MENUPRINCIPAL_H
