
#include "view/app.h"

#include <QSurfaceFormat>

int main(int argc, char *argv[]) {
    QSurfaceFormat format;
    format.setSamples(4);
    QSurfaceFormat::setDefaultFormat(format);

    RocketCad::View::App app(argc, argv);
    app.showRecents();
    return app.exec();
}
