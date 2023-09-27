
#pragma once

#include "object.h"

ROCKETCAD_OBJECT_NAMESPACE_BEGIN

class TubingObject final : public RocketObject {
public:

    void serialize(json &out) const override;
    void deserialize(const json &in) override;

    inline bool isHollow() {
        return inside_radius != 0 && inside_radius != outside_radius;
    }

private: 
    double inside_radius; // R_1
    double outside_radius; // R_2
    double wall_thickness;
    double length;

};

ROCKETCAD_OBJECT_NAMESPACE_END

