#pragma once

#ifndef RESOURCE_LOCATION_H
#define RESOURCE_LOCATION_H

#include <filesystem>

class ResourceLocation
{
private:
    std::filesystem::path source;
    std::filesystem::path target;
    std::filesystem::path ground;
public:
    ResourceLocation(){};

    const std::filesystem::path get_source() const;
    const std::filesystem::path get_target() const;
    const std::filesystem::path get_ground() const;

    void set_source(const std::filesystem::path source);
    void set_target(const std::filesystem::path target);
    void set_ground(const std::filesystem::path ground);
};

#endif //RESOURCE_LOCATION_H