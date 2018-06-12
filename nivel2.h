#ifndef NIVEL2_H
#define NIVEL2_H

#include <QDialog>
#include <QMovie>
#include "win1.h"
#include "ui_nivel1.h"
#include "nivel1.h"
#include "listaniveles.h"
#include "menuprincipal.h"

namespace Ui {
class Nivel2;
}

class Nivel2 : public QDialog
{
    Q_OBJECT

public:
    explicit Nivel2(QWidget *parent = 0);
    ~Nivel2();
    QMovie *movie;
    Win1 *win1;

private:
    Ui::Nivel2 *ui;
};

#endif // NIVEL2_H
