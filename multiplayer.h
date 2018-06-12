#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

//#include <QMediaPlayer>
#include <QDialog>
#include <QMovie>

namespace Ui {
class Multiplayer;
}

class Multiplayer : public QDialog
{
    Q_OBJECT

public:
    explicit Multiplayer(QWidget *parent = 0);
    ~Multiplayer();
//    QMediaPlayer * musicm;
    QMovie *moviem;
private:
    Ui::Multiplayer *ui;
};

#endif // MULTIPLAYER_H
