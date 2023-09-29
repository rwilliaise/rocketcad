
#pragma once

#include "object.h"

ROCKETCAD_OBJECT_NAMESPACE_BEGIN

class FinSet : public RocketObject {
public:

    void serialize(json &out) const override;
    void deserialize(const json &in) override;

private:
    double fins;

};

ROCKETCAD_OBJECT_NAMESPACE_END

