
#pragma once

#include <rocketcad.h>
#include <view/workbench_window/ui_workbench_window.h>

#include <data/document.h>

#include <QMainWindow>

ROCKETCAD_NAMESPACE_BEGIN(View)

class WorkbenchWindow : public QMainWindow {
Q_OBJECT
public:
    explicit WorkbenchWindow(Data::SharedDocument doc);

private slots:
    void closeProject();

private:
    Data::SharedDocument open_document;
    Ui::WorkbenchWindow ui;

};

ROCKETCAD_NAMESPACE_END(View)
