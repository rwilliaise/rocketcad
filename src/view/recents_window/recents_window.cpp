
#include "recents_window.h"

#include "data/objects/tubing_object.h"
#include "view/app.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

RecentsWindow::RecentsWindow() {
    ui.setupUi(this);
    ui.version->setText("Version " ROCKETCAD_VERSION);
}

void RecentsWindow::newProject() {
    hide();
    auto project = std::make_shared<Data::Document>();
    project->addChild(std::make_shared<Data::Object::TubingObject>());
    app().openProject(project);
}

ROCKETCAD_NAMESPACE_END(View)

