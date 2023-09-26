
#include "view/app.h"

int main(int argc, char *argv[]) {
    RocketCad::View::App app(argc, argv);
    app.showRecents();
    return app.exec();
}
