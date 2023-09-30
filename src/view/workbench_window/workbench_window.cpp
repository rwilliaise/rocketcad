
#include "workbench_window.h"

#include "data/document.h"
#include "view/app.h"
#include "view/workbench_window/explorer_item_model.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

WorkbenchWindow::WorkbenchWindow(Data::SharedDocument doc) : open_document(doc) {
    ui.setupUi(this);
    ui.explorer_tree->setModel(new ExplorerItemModel(open_document, this));
}

void WorkbenchWindow::closeProject() {
    app().closeProject();
}

ROCKETCAD_NAMESPACE_END(View)
