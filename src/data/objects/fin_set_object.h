
#pragma once

#include "object.h"

ROCKETCAD_OBJECT_NAMESPACE_BEGIN

class FinSet : public RocketObject {
public:

    void serialize(json &out) const override;
    void deserialize(const json &in) override;

    const char *getName() override {
        return "Fin Set";
    }

private:
    double fins;

};

ROCKETCAD_OBJECT_NAMESPACE_END

