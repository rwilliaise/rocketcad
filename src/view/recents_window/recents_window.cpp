
#include "recents_window.h"
#include "view/rocketcad_app.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

RecentsWindow::RecentsWindow() {
    ui.setupUi(this);
}

void RecentsWindow::newProject() {
    hide();
    app().showWorkbench();
}

ROCKETCAD_NAMESPACE_END(View)

