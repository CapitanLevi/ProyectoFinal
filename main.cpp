#include "menuprincipal.h"
#include <QApplication>

MenuPrincipal *w;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    w = new MenuPrincipal();
    w->show();

    return a.exec();
}
