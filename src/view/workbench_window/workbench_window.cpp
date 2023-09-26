
#include "workbench_window.h"

#include "view/app.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

WorkbenchWindow::WorkbenchWindow(Data::SharedDocument doc) : open_document(doc) {
    ui.setupUi(this);
}

void WorkbenchWindow::closeProject() {
    app().closeProject();
}

ROCKETCAD_NAMESPACE_END(View)
