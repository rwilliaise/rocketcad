
#include "viewport_widget.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

ViewportWidget::ViewportWidget(QWidget *parent) : QOpenGLWidget(parent) {}

void ViewportWidget::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(1, 0, 0, 1);
}

void ViewportWidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void ViewportWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);
}

ROCKETCAD_NAMESPACE_END(View)
