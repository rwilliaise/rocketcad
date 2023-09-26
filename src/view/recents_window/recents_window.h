
#pragma once

#include <rocketcad.h>

#include <view/recents_window/ui_recents_window.h>

ROCKETCAD_NAMESPACE_BEGIN(View)

class RecentsWindow : public QMainWindow {
Q_OBJECT
public:
    RecentsWindow();

private slots:
    void newProject();

private:
    Ui::RecentsWindow ui;

};

ROCKETCAD_NAMESPACE_END(View)

