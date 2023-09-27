
#include "recents_window.h"
#include "view/app.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

RecentsWindow::RecentsWindow() {
    ui.setupUi(this);
    ui.version->setText("Version " ROCKETCAD_VERSION);
}

void RecentsWindow::newProject() {
    hide();
    app().openProject(std::make_shared<Data::Document>());
}

ROCKETCAD_NAMESPACE_END(View)

