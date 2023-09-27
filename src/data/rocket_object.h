
#pragma once

#include <rocketcad.h>
#include <data/data.h>
#include <vector>

ROCKETCAD_NAMESPACE_BEGIN(Data)

enum RocketObjectType {
    ROCKET_OBJECT_TUBING,
    ROCKET_OBJECT_UNKNOWN = -1,
};

NLOHMANN_JSON_SERIALIZE_ENUM(RocketObjectType, {
    { ROCKET_OBJECT_UNKNOWN, nullptr },
    { ROCKET_OBJECT_TUBING, "tubing" },
})

class RocketObject {
public:
    virtual ~RocketObject() {}

    virtual void serialize(json &out) const = 0;
    virtual void deserialize(const json &in) = 0;

    void serializeChildren(json &out) const;
    void deserializeChildren(const json &in);

    static std::shared_ptr<RocketObject> fromType(RocketObjectType type);

protected:
    std::vector<std::shared_ptr<RocketObject>> children;

};

ROCKETCAD_NAMESPACE_END(Data)

