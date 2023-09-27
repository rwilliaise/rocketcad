
#include "app.h"

#include <QFileDialog>
#include <QStandardPaths>
#include <filesystem>

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
    workbench_window->close();
    workbench_window = std::unique_ptr<WorkbenchWindow>();
    open_document = Data::SharedDocument();
}

void App::selectProjectFromFile() {
    QString filename = QFileDialog::getOpenFileName(
        nullptr,
        tr("Open Project"),
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation),
        "Project files (*.rkt, *.ork)" // .ork is OpenRocket document
    );

    if (filename.isEmpty()) return;
    std::filesystem::path path(filename.toStdString());
    Data::SharedDocument document = std::make_shared<Data::Document>(path);
}

App &app() {
    return *static_cast<App *>(qApp);
}

ROCKETCAD_NAMESPACE_END(View)

