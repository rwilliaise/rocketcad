
#pragma once

#include <rocketcad.h>

#include <stdexcept>

ROCKETCAD_NAMESPACE_BEGIN(View)

class RenderException : public std::runtime_error {
public:
    
    RenderException(const char *message) : std::runtime_error(message) {}

    inline const char *what() const noexcept override {
        return exception::what();
    }
};

ROCKETCAD_NAMESPACE_END(View)
