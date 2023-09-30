
#pragma once

#include "render.h"
#include "render_object.h"

#include <data/document.h>

ROCKETCAD_RENDER_NAMESPACE_BEGIN

class RenderModel {
public:

    RenderModel(Data::SharedDocument document) : document(document) {};

    void update();

private:
    std::vector<RenderObject> objects;
    Data::SharedDocument document;

};

ROCKETCAD_RENDER_NAMESPACE_END
