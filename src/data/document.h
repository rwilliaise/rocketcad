
#pragma once

#include <rocketcad.h>

#include <filesystem>
#include <memory>

#include "rocket_object.h"

ROCKETCAD_NAMESPACE_BEGIN(Data)

class Document final : public std::enable_shared_from_this<Document>, public RocketObject {
public: 
    Document() {};
    Document(std::filesystem::path &path);

    void load();
    void save() const;

    void serialize(json &out) const override;
    void deserialize(const json &in) override;

    inline void setPath(std::filesystem::path &path) {
        this->path = path;
    }

private:
    std::filesystem::path path;
    std::string version = ROCKETCAD_VERSION;
    
};

using WeakDocument = std::weak_ptr<Document>;
using SharedDocument = std::shared_ptr<Document>;

ROCKETCAD_NAMESPACE_END(Data)
