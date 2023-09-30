
#include "render_object.h"
#include <GL/glew.h>

ROCKETCAD_RENDER_NAMESPACE_BEGIN

RenderObject::RenderObject(std::shared_ptr<Data::RocketObject> object) : object(object) {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, vbo);
    update();
}

RenderObject::~RenderObject() {
    glDeleteVertexArrays(1, &vao);
    glDeleteBuffers(1, vbo);
}

void RenderObject::bind() {
    glBindVertexArray(vao);
}

void RenderObject::update() {
    if (!object) return;

    const float data[] = {
        0.0, 0.5, 0.0,
        -0.5, -0.5, 0.0,
        0.5, -0.5, 0.0
    };

    bind();
    glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_DYNAMIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
}

ROCKETCAD_RENDER_NAMESPACE_END
