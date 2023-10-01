
#pragma once

#include "render.h"

#include <data/rocket_object.h>
#include <cstdint>
#include <memory>

ROCKETCAD_RENDER_NAMESPACE_BEGIN

class RenderObject {
public:
    RenderObject(std::shared_ptr<Data::RocketObject> object);
    ~RenderObject();

    RenderObject(const RenderObject &) = delete;
    RenderObject(RenderObject &&) noexcept = default;
    RenderObject &operator=(const RenderObject &) = delete;
    RenderObject &operator=(RenderObject &&) noexcept = default;

    void generate();
    void bind();
    void update();

private:
    std::shared_ptr<Data::RocketObject> object;

    std::uint32_t vao;
    std::uint32_t vbo[1];

};

ROCKETCAD_RENDER_NAMESPACE_END

