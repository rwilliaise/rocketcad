
#include "rocketcad_app.h"


ROCKETCAD_NAMESPACE_BEGIN(View)

RocketCadApp::RocketCadApp(int &argc, char *argv[]) : QApplication(argc, argv) {
    setApplicationName("RocketCAD");
    setOrganizationName("rwilliaise");
    setOrganizationDomain("io.github.rwilliaise");
}

void RocketCadApp::showRecents() {
    if (!recents_window.get()) {
        recents_window = std::make_unique<RecentsWindow>();
    }
    recents_window->show();
}

void RocketCadApp::showWorkbench() {
    // if (!workbench_window.get()) {
    //     workbench_window = std::unique_ptr<WorkbenchWindow>();
    // }
    // workbench_window->show();
}

RocketCadApp &app() {
    return *static_cast<RocketCadApp *>(qApp);
}

ROCKETCAD_NAMESPACE_END(View)

