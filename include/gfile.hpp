#pragma once

#ifndef GFILE_H
#define GFILE_H

#include "graphcharacteristics.hpp"
#include <filesystem>
#include <string>

namespace sfs = std::filesystem;

class GFile
{
private:
    sfs::path path;
    GraphCharacteristics characteristics;

public:
    GFile(){}; // to delete after implementation
    virtual ~GFile() = default; // make this type polymorphic
    GFile(const sfs::path filepath);

    const sfs::path relative_toward(const sfs::path base_path) const;
    const sfs::path absolute() const;

    // getters
    const sfs::path get_path() const;
    const GraphCharacteristics get_characteristics() const;
};


#endif //GFILE_H