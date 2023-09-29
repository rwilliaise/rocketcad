
#include "viewport_widget.h"

ROCKETCAD_NAMESPACE_BEGIN(View)

ViewportWidget::ViewportWidget(QWidget *parent) : QOpenGLWidget(parent) {}

void ViewportWidget::initializeGL() {
    renderer.initialize();
}

void ViewportWidget::resizeGL(int w, int h) {
    renderer.resize(w, h);
}

void ViewportWidget::paintGL() {
    renderer.paint();
}

ROCKETCAD_NAMESPACE_END(View)
