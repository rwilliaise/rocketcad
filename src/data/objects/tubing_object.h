
#pragma once

#include "object.h"

ROCKETCAD_OBJECT_NAMESPACE_BEGIN

class TubingObject final : public RocketObject {
public:

    void serialize(json &out) const override;
    void deserialize(const json &in) override;
};

ROCKETCAD_OBJECT_NAMESPACE_END

