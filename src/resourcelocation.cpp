#include "resourcelocation.hpp"

const std::filesystem::path ResourceLocation::get_source() const
{
    return this->source;
}

const std::filesystem::path ResourceLocation::get_target() const
{
    return this->target;
}

const std::filesystem::path ResourceLocation::get_ground() const
{
    return this->ground;
}

void ResourceLocation::set_source(const std::filesystem::path source)
{
    this->source = std::move(source);
}

void ResourceLocation::set_target(const std::filesystem::path target)
{
    this->target = std::move(target);
}

void ResourceLocation::set_ground(const std::filesystem::path ground)
{
    this->ground = std::move(ground);
}
