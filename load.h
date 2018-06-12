#ifndef LOAD_H
#define LOAD_H

#include <QDialog>

namespace Ui {
class Load;
}

class Load : public QDialog
{
    Q_OBJECT

public:
    explicit Load(QWidget *parent = 0);
    ~Load();

private slots:
    void on_clave_returnPressed();

private:
    Ui::Load *ui;
};

#endif // LOAD_H
