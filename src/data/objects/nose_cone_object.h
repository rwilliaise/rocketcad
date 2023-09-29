
#pragma once

#include "object.h"
#include "tubing_object.h"

ROCKETCAD_OBJECT_NAMESPACE_BEGIN

class NoseConeObject : public TubingObject {
public:

    void serialize(json &out) const override;
    void deserialize(const json &in) override;

    const char *getName() override {
        return "Nose Cone";
    }

private:
    double shape;
};

ROCKETCAD_OBJECT_NAMESPACE_END
