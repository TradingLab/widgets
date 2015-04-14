#include <QtGui/QApplication>
#include "lineedits.h"


int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    lineedits foo;
    foo.show();
    return app.exec();
}
