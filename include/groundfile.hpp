#pragma once

#ifndef GROUND_FILE_H
#define GROUND_FILE_H

#include "gfile.hpp"
#include <map>

class GroundFile : public GFile//, public ITargetable
{
private:
    std::map<std::string, int> adjacencies;

public:
    GroundFile() {}; // to delete after full implementation
    GroundFile(const std::filesystem::path path) : GFile(path) {};

    virtual void build_target_absolute(const ResourceLocation resource) override;
    virtual std::string build_target_filename() const override;

    // getters, setters
    const std::map<std::string, int> get_adjacencies() const;
    void set_adjacencies(std::map<std::string, int> adjacencies);
};


#endif //GROUND_FILE_H