
#include "rocket_object.h"

#include "data/objects/tubing_object.h"
#include "data/objects/nose_cone_object.h"

ROCKETCAD_NAMESPACE_BEGIN(Data)

size_t RocketObject::global_pid = 0;

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
        if (!out) continue;
        out->deserialize(child);
        children.push_back(out);
    }
}

void RocketObject::addChild(std::shared_ptr<RocketObject> child) {
    child->setParent(shared_from_this());
}

void RocketObject::removeChild(std::shared_ptr<RocketObject> child) {
    child->setParent(std::shared_ptr<RocketObject>());
}

void RocketObject::setParent(std::shared_ptr<RocketObject> new_parent) {
    if (new_parent)
        new_parent->children.push_back(shared_from_this());
    else if (parent)
        for (int i = 0; i < parent->children.size(); i++) {
            std::shared_ptr<Data::RocketObject> child = parent->children[i];
            if (child.get() == this) {
                parent->children.erase(parent->children.begin() + i);
                break;
            }
        }
    parent = new_parent;
}

int RocketObject::row() const {
    if (!parent) return -1;
    for (int i = 0; i < parent->children.size(); i++) {
        if (parent->children[i].get() == this) {
            return i;
        }
    }
    return -1;
}

std::shared_ptr<RocketObject> RocketObject::fromType(RocketObjectType type) {
    switch(type) {
        case ROCKET_OBJECT_TUBING: return std::make_shared<Object::TubingObject>();
        case ROCKET_OBJECT_NOSE_CONE: return std::make_shared<Object::NoseConeObject>();
        default: break;
    }

    return std::shared_ptr<RocketObject>();
}

ROCKETCAD_NAMESPACE_END(Data)

