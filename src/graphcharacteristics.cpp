#include "graphcharacteristics.hpp"

GraphCharacteristics::GraphCharacteristics()
{
}

GraphCharacteristics::GraphCharacteristics(const std::filesystem::path filepath)
{
    this->decompose_path(filepath);
}

const std::string GraphCharacteristics::get_congruence() const
{
    return this->congruence;
}

const std::string GraphCharacteristics::get_group() const
{
    return this->group;
}

const std::string GraphCharacteristics::get_size() const
{
    return this->size;
}

const std::string GraphCharacteristics::get_identifier() const
{
    return this->identifier;
}

void GraphCharacteristics::set_congruence(const std::string congruence)
{
    this->congruence = congruence;
}

void GraphCharacteristics::set_group(const std::string group)
{
    this->group = group;
}

void GraphCharacteristics::set_size(const std::string size)
{
    this->size = size;
}

void GraphCharacteristics::set_identifier(const std::string identifier)
{
    this->identifier = identifier;
}

void GraphCharacteristics::decompose_path(const std::filesystem::path path)
{
    std::vector<std::string> filename_parts;
    boost::split(filename_parts, path.stem().string(), boost::is_any_of("_"));

    assert(filename_parts.size() == 3);
    this->congruence = filename_parts.at(0);
    this->group = filename_parts.at(1);
    this->size = filename_parts.at(2);
    this->identifier = path.extension().string().substr(1);
}
