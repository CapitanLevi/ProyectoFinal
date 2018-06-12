#ifndef GANADORM_H
#define GANADORM_H

#include <QDialog>

namespace Ui {
class GanadorM;
}

class GanadorM : public QDialog
{
    Q_OBJECT

public:
    explicit GanadorM(QWidget *parent = 0);
    ~GanadorM();

private:
    Ui::GanadorM *ui;
};

#endif // GANADORM_H
