
#pragma once

#include "render.h"
#include "render_object.h"

#include <cstdint>

ROCKETCAD_RENDER_NAMESPACE_BEGIN

class Renderer {
public:

    void initialize();
    void resize(int w, int h);
    void paint();

private:

    RenderObject object = RenderObject(std::shared_ptr<Data::RocketObject>());
};

ROCKETCAD_RENDER_NAMESPACE_END

