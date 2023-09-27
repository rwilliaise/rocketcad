
#include "rocket_object.h"

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
    auto children = in["children"];

    if (children.is_array()) {
        for (auto child : children) {
            auto json_type = child["type"];
            if (!json_type.is_string()) continue;
            
            auto type = json_type.template get<RocketObjectType>();
            
        }
    }
}

std::shared_ptr<RocketObject> fromType(RocketObjectType type) {

    return std::shared_ptr<RocketObject>();
}

ROCKETCAD_NAMESPACE_END(Data)


