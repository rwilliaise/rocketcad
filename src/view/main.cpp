
#include "view/rocketcad_app.h"

int main(int argc, char *argv[]) {
    RocketCad::View::RocketCadApp app(argc, argv);
    app.showRecents();
    return app.exec();
}
