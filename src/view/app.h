
#pragma once

#include <rocketcad.h>

#include <data/document.h>

#include "recents_window/recents_window.h"
#include "workbench_window/workbench_window.h"

#include <QApplication>
#include <memory>

ROCKETCAD_NAMESPACE_BEGIN(View)

class App : public QApplication {
Q_OBJECT
public:
    explicit App(int &argc, char *argv[]);
    
    void showRecents();

    void openProject(Data::SharedDocument document);
    void closeProject();

    inline Data::WeakDocument openDocument() {
        return Data::WeakDocument(open_document);
    }

private:

    Data::SharedDocument open_document;
    
    std::unique_ptr<RecentsWindow> recents_window;
    std::unique_ptr<WorkbenchWindow> workbench_window;
};

App &app();

ROCKETCAD_NAMESPACE_END(View)

