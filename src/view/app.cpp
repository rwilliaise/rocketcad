
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

void App::openProject(Data::SharedDocument document) {
    open_document = document;
    workbench_window = std::make_unique<WorkbenchWindow>(document);
    workbench_window->show();
}

void App::closeProject() {
    WorkbenchWindow *window = workbench_window.release();
    window->close();
    delete window;

    open_document = Data::SharedDocument();
}

App &app() {
    return *static_cast<App *>(qApp);
}

ROCKETCAD_NAMESPACE_END(View)

