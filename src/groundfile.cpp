#include "groundfile.hpp"

void GroundFile::build_target_absolute(const ResourceLocation resource)
{
}

std::string GroundFile::build_target_filename() const
{
    return std::string();
}

const std::map<std::string, int> GroundFile::get_adjacencies() const
{
    return this->adjacencies;
}

void GroundFile::set_adjacencies(std::map<std::string, int> adjacencies)
{
    this->adjacencies = std::move(adjacencies);
}
