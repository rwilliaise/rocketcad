
#include "document.h"
#include "data.h"
#include <fstream>

ROCKETCAD_NAMESPACE_BEGIN(Data)

Document::Document(std::filesystem::path &path) : path(path) {
}

void Document::load() {
    if (path.empty()) return;
    std::ifstream stream(path);
    json in = json::parse(stream);
    deserialize(in);
}

void Document::save() const {
    if (path.empty()) return;
    json out = json({});
    serialize(out);
}

void Document::serialize(json &out) const {
    serializeChildren(out);
    RC_SAVE(version);
}

void Document::deserialize(const json &in) {
    deserializeChildren(in);
    RC_LOAD(version);
}

ROCKETCAD_NAMESPACE_END(Data)
