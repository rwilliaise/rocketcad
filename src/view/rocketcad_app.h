
#pragma once

#include <rocketcad.h>

#include "recents_window/recents_window.h"

#include <QApplication>
#include <memory>

ROCKETCAD_NAMESPACE_BEGIN(View)

class RecentsWindow;
// class WorkbenchWindow;
class RocketCadApp : public QApplication {
Q_OBJECT
public:
    explicit RocketCadApp(int &argc, char *argv[]);
    
    void showRecents();
    void showWorkbench();

private:
    
    std::unique_ptr<RecentsWindow> recents_window;
    // std::unique_ptr<WorkbenchWindow> workbench_window;
};

RocketCadApp &app();

ROCKETCAD_NAMESPACE_END(View)

