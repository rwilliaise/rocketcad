
#include "nose_cone_object.h"

ROCKETCAD_OBJECT_NAMESPACE_BEGIN

void NoseConeObject::serialize(json &out) const {
    TubingObject::serialize(out);
    RC_SAVE(shape);
}

void NoseConeObject::deserialize(const json &in) {
    TubingObject::deserialize(in);
    RC_LOAD(shape);
}

ROCKETCAD_OBJECT_NAMESPACE_END
