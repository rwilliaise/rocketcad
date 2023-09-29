
#pragma once

#include "object.h"
#include "tubing_object.h"

ROCKETCAD_OBJECT_NAMESPACE_BEGIN

class ConnectorObject : public TubingObject {
public:

    void serialize(json &out) const override;
    void deserialize(const json &in) override;

    const char *getName() override {
        return "Connector";
    }

private:
    double angle;
};

ROCKETCAD_OBJECT_NAMESPACE_END
