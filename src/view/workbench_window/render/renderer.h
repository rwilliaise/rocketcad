
#pragma once

#include "data/rocket_object.h"
#include "render.h"
#include "render_object.h"

#include <cstdint>

ROCKETCAD_RENDER_NAMESPACE_BEGIN

class Renderer {
public:
    Renderer() : object(std::shared_ptr<Data::RocketObject>()) {}

    void initialize();
    void resize(int w, int h);
    void paint();

private:

    RenderObject object;
};

ROCKETCAD_RENDER_NAMESPACE_END

