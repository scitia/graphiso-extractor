#pragma once

#ifndef GROUND_FILE_H
#define GROUND_FILE_H

#include "gfile.hpp"
#include <map>

class GroundFile : public GFile
{
private:
    std::map<std::string, int> adjacencies;

public:
    GroundFile() {};
    GroundFile(const std::filesystem::path path) : GFile(path) {};
    GroundFile(const std::filesystem::path path, const ResourceLocation resource) : GFile(path, resource) {};

    virtual void validate() const;
    virtual void build_target_absolute() override;
    virtual std::string build_target_filename() const override;

    // getters, setters
    const std::map<std::string, int> get_adjacencies() const;
    void set_adjacencies(std::map<std::string, int> adjacencies);
};

#endif //GROUND_FILE_H