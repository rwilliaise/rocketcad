
#include "app.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

App::App(int &argc, char *argv[]) : QApplication(argc, argv) {
    setApplicationName("RocketCAD");
    setOrganizationName("rwilliaise");
    setOrganizationDomain("io.github.rwilliaise");
}

void App::showRecents() {
    if (!recents_window.get()) {
        recents_window = std::make_unique<RecentsWindow>();
    }
    recents_window->show();
}

void App::showWorkbench() {
    if (!workbench_window.get()) {
        workbench_window = std::make_unique<WorkbenchWindow>();
    }
    workbench_window->show();
}

App &app() {
    return *static_cast<App *>(qApp);
}

ROCKETCAD_NAMESPACE_END(View)

