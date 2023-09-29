
#pragma once

#include <rocketcad.h>
#include "render/renderer.h"

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

ROCKETCAD_NAMESPACE_BEGIN(View)

class WorkbenchWindow;
class ViewportWidget : public QOpenGLWidget {
Q_OBJECT
public:
    ViewportWidget(QWidget *parent = nullptr);

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    inline WorkbenchWindow *getWorkbench() {
        return reinterpret_cast<WorkbenchWindow *>(parent());
    }

    Render::Renderer renderer;
};

ROCKETCAD_NAMESPACE_END(View)
