
#pragma once

#include <rocketcad.h>

#include <filesystem>
#include <memory>

ROCKETCAD_NAMESPACE_BEGIN(Data)

class Document : public std::enable_shared_from_this<Document> {
public: 
    Document(std::filesystem::path &path);

    void save();

    inline void setPath(std::filesystem::path &path) {
        this->path = path;
    }

private:
    std::filesystem::path path;
    

};

typedef std::weak_ptr<Document> WeakDocument;
typedef std::shared_ptr<Document> SharedDocument;

ROCKETCAD_NAMESPACE_END(Data)
