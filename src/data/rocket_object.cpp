
#include "rocket_object.h"
#include "data/objects/tubing_object.h"

ROCKETCAD_NAMESPACE_BEGIN(Data)

void RocketObject::serializeChildren(json &out) const {
    auto json_children = json::array();

    for (std::shared_ptr<RocketObject> object : children) {
        json json_object({});
        object->serialize(json_object);
        json_children.push_back(json_object);
    }

    out["children"] = json_children;
}

void RocketObject::deserializeChildren(const json &in) {
    auto json_children = in["children"];
    if (json_children.is_array()) return;

    for (auto child : json_children) {
        auto json_type = child["type"];
        if (!json_type.is_string()) continue;
        auto type = json_type.template get<RocketObjectType>();
        auto out = fromType(type);
        if (!out.get()) continue;
        out->deserialize(child);
        children.push_back(out);
    }
}

std::shared_ptr<RocketObject> RocketObject::fromType(RocketObjectType type) {
    switch(type) {
        case ROCKET_OBJECT_TUBING: return std::make_shared<Object::TubingObject>();
        default: break;
    }

    return std::shared_ptr<RocketObject>();
}

ROCKETCAD_NAMESPACE_END(Data)


