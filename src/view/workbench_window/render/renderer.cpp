
#include "renderer.h"
#include "render_exception.h"

#include <GL/glew.h>
#include <iostream>

ROCKETCAD_RENDER_NAMESPACE_BEGIN

#ifndef NDEBUG
static const char *stringifyGlType(GLenum type) {
    switch (type) {
        case GL_DEBUG_TYPE_ERROR: return "ERROR";
        case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR: return "DEPRECATED";
        case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR: return "UNDEFINED";
        case GL_DEBUG_TYPE_PERFORMANCE: return "PERFORMANCE";
        default: return "NICHE";
    }
}

static const char *stringifyGlSeverity(GLenum type) {
    switch (type) {
        case GL_DEBUG_SEVERITY_HIGH: return "HIGH";
        case GL_DEBUG_SEVERITY_MEDIUM: return "MEDIUM";
        case GL_DEBUG_SEVERITY_LOW: return "LOW";
        default: return "INFO";
    }
}

static void debugCallback(
    GLenum source,
    GLenum type,
    GLuint id,
    GLenum severity,
    GLsizei length,
    const GLchar *message,
    const void *ud
) {
    const char *string_type = stringifyGlType(type);
    const char *string_severity = stringifyGlSeverity(severity);
    if (ud) {
        const Renderer *renderer = reinterpret_cast<const Renderer *>(ud);
    }
    std::cout << "[GL " << string_type << " - " << string_severity << "] " << message << "\n";
}
#endif

void Renderer::initialize() {
    if (glewInit() != GLEW_OK) {
        throw RenderException("GLEW failed to initialize.");
    }

    if (!GL_VERSION_3_0) throw RenderException("GL too old!");

#ifndef NDEBUG
    if (GL_KHR_debug) {
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(debugCallback, this);
    }
#endif

    glEnable(GL_MULTISAMPLE);

    glClearColor(1, 0, 0, 1);
    glGenVertexArrays(1, &triangle_vao);
    glGenBuffers(1, &triangle_vbo);

    float triangle[] = {
        0, 0.5, 0,
        0.5, -0.5, 0,
        -0.5, -0.5, 0,
    };

    glBindVertexArray(triangle_vao);
    glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
    glEnableVertexAttribArray(0);
}

void Renderer::resize(int w, int h) {
    glViewport(0, 0, w, h);
}

void Renderer::paint() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBindVertexArray(triangle_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

ROCKETCAD_RENDER_NAMESPACE_END

