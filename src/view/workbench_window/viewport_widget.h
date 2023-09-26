
#pragma once

#include <rocketcad.h>

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

ROCKETCAD_NAMESPACE_BEGIN(View)

class WorkbenchWindow;
class ViewportWidget : public QOpenGLWidget, protected QOpenGLFunctions {
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
};

ROCKETCAD_NAMESPACE_END(View)
