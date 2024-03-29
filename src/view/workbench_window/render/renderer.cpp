
#include "renderer.h"
#include "render_exception.h"

#include <GL/glew.h>
#include <iostream>

#if !NDEBUG && !GL_KHR_debug
#warning "GL_KHR_debug is not available - some debug messages will not be visible."
#endif

#if !GL_VERSION_3_0
#error "GL version too old."
#endif

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

#if !NDEBUG && GL_KHR_debug
    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(debugCallback, this);
#endif

    glEnable(GL_MULTISAMPLE);
    glClearColor(1, 0, 0, 1);
    object.generate();
}

void Renderer::resize(int w, int h) {
    glViewport(0, 0, w, h);
}

void Renderer::paint() {
    glClear(GL_COLOR_BUFFER_BIT);

    object.bind();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

ROCKETCAD_RENDER_NAMESPACE_END

