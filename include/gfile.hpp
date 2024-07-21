#pragma once

#ifndef GFILE_H
#define GFILE_H

#include "fileio.hpp"
#include "graphcharacteristics.hpp"
#include "resourcelocation.hpp"
#include <boost/algorithm/string.hpp>
#include <filesystem>
#include <vector>
#include <string>

namespace sfs = std::filesystem;

class GFile
{
private:
    sfs::path path;
    sfs::path target_path;
    GraphCharacteristics characteristics;

public:
    GFile(){};
    GFile(const sfs::path filepath);
    virtual ~GFile() = default;

    virtual void build_target_absolute(const ResourceLocation resource) = 0;
    virtual std::string build_target_filename() const = 0;

    const sfs::path absolute() const;
    const sfs::path get_path() const;
    const sfs::path get_target_path() const;
    void set_target_path(std::filesystem::path target_path);
    const GraphCharacteristics get_characteristics() const;
    const sfs::path relative_toward(const sfs::path base_path) const;
};

#endif //GFILE_H