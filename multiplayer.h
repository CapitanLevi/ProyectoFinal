#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include <QMediaPlayer>
#include <QDialog>

namespace Ui {
class Multiplayer;
}

class Multiplayer : public QDialog
{
    Q_OBJECT

public:
    explicit Multiplayer(QWidget *parent = 0);
    ~Multiplayer();

    QMediaPlayer * musicm;

private:
    Ui::Multiplayer *ui;
};

#endif // MULTIPLAYER_H
