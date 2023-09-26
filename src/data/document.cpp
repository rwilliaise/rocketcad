
#include "document.h"
#include <fstream>

ROCKETCAD_NAMESPACE_BEGIN(Data)

Document::Document(std::filesystem::path &path) : path(path) {
}

void Document::save() {
    std::ofstream stream(path);
}

ROCKETCAD_NAMESPACE_END(Data)
