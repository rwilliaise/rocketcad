
#pragma once

#include <rocketcad.h>
#include <data/data.h>
#include <vector>

#define ROCKETCAD_OBJECT_DEFINE_PROPERTIES(name) extern const std::unordered_map<
#define ROCKETCAD_OBJECT_INIT_PROPERTIES(name, map) 

ROCKETCAD_NAMESPACE_BEGIN(Data)

enum RocketObjectType {
    ROCKET_OBJECT_TUBING,
    ROCKET_OBJECT_NOSE_CONE,
    ROCKET_OBJECT_UNKNOWN = -1,
};

NLOHMANN_JSON_SERIALIZE_ENUM(RocketObjectType, {
    { ROCKET_OBJECT_UNKNOWN, nullptr },
    { ROCKET_OBJECT_TUBING, "tubing" },
    { ROCKET_OBJECT_NOSE_CONE, "nose_cone" },
})

class RocketObject : public std::enable_shared_from_this<RocketObject> {
public:
    virtual ~RocketObject() {}

    virtual void serialize(json &out) const = 0;
    virtual void deserialize(const json &in) = 0;
    virtual const char *getName() const = 0;

    void serializeChildren(json &out) const;
    void deserializeChildren(const json &in);

    inline std::shared_ptr<RocketObject> getChild(int row) {
        return children[row];
    }

    inline int getChildCount() {
        return children.size();
    }

    void addChild(std::shared_ptr<RocketObject> child);
    void removeChild(std::shared_ptr<RocketObject> child);
    void setParent(std::shared_ptr<RocketObject> new_parent);
    int row() const;

    inline std::shared_ptr<RocketObject> getParent() const {
        return parent.lock();
    }

    static std::shared_ptr<RocketObject> fromType(RocketObjectType type);

protected:
    static size_t global_pid;
    size_t pid = global_pid++; // unique id for the process

protected:
    std::vector<std::shared_ptr<RocketObject>> children;
    std::weak_ptr<RocketObject> parent;

};

ROCKETCAD_NAMESPACE_END(Data)

