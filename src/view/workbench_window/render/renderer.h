
#include "render.h"

#include <cstdint>

ROCKETCAD_RENDER_NAMESPACE_BEGIN

class Renderer {
public:

    void initialize();
    void resize(int w, int h);
    void paint();

private:

    uint32_t triangle_vao;
    uint32_t triangle_vbo;
};

ROCKETCAD_RENDER_NAMESPACE_END

