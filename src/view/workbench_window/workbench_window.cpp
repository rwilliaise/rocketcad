
#include "workbench_window.h"

#include "data/document.h"
#include "view/app.h"
#include "view/workbench_window/explorer_item_model.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

WorkbenchWindow::WorkbenchWindow(Data::SharedDocument doc) : open_document(doc) {
    ui.setupUi(this);
    
    ExplorerItemModel *model = new ExplorerItemModel(open_document, ui.explorer_tree);
    ui.explorer_tree->setModel(model);
    ui.explorer_tree->setRootIndex(model->index(0, 0));
}

void WorkbenchWindow::closeProject() {
    app().closeProject();
}

ROCKETCAD_NAMESPACE_END(View)
