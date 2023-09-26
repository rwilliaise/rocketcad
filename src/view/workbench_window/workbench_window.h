
#pragma once

#include <rocketcad.h>
#include <view/workbench_window/ui_workbench_window.h>

#include <QMainWindow>

ROCKETCAD_NAMESPACE_BEGIN(View)

class WorkbenchWindow : public QMainWindow {
Q_OBJECT
public:
    WorkbenchWindow();

private:
    Ui::WorkbenchWindow ui;

};

ROCKETCAD_NAMESPACE_END(View)
