
#pragma once

#include <data/json.hpp>

#define RC_SAVE(name) out[#name] = name
#define RC_LOAD(name) name = in[#name]

using json = nlohmann::json;
