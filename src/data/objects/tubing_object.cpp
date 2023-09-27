
#include "tubing_object.h"

ROCKETCAD_OBJECT_NAMESPACE_BEGIN

void TubingObject::serialize(json &out) const {
    serializeChildren(out);
    RC_SAVE(inside_radius);
    RC_SAVE(outside_radius);
    RC_SAVE(wall_thickness);
    RC_SAVE(length);
}

void TubingObject::deserialize(const json &in) { 
    deserializeChildren(in);
    RC_LOAD(inside_radius);
    RC_LOAD(outside_radius);
    RC_LOAD(wall_thickness);
    RC_LOAD(length);
}

ROCKETCAD_OBJECT_NAMESPACE_END
