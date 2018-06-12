#ifndef GANADORM2_H
#define GANADORM2_H

#include <QDialog>

namespace Ui {
class GanadorM2;
}

class GanadorM2 : public QDialog
{
    Q_OBJECT

public:
    explicit GanadorM2(QWidget *parent = 0);
    ~GanadorM2();

private:
    Ui::GanadorM2 *ui;
};

#endif // GANADORM2_H
