
#pragma once

#include "object.h"
#include "tubing_object.h"

ROCKETCAD_OBJECT_NAMESPACE_BEGIN

class ConnectorObject : public TubingObject {
public:

    void serialize(json &out) const override;
    void deserialize(const json &in) override;

private:
    double angle;
};

ROCKETCAD_OBJECT_NAMESPACE_END
