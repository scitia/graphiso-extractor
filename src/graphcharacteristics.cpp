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

const int GraphCharacteristics::get_nodes() const
{
    return this->nodes;
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

void GraphCharacteristics::set_nodes(const int nodes)
{
    this->nodes = nodes;
}

void GraphCharacteristics::decompose_path(const std::filesystem::path path)
{
    std::string extension = path.extension().string();
    if (FileIO::GTR_EXTENSION == extension) {
        this->decompose_path_ground(path);
    } else {
        this->decompose_path_graph(path);
    }
}

void GraphCharacteristics::decompose_path_graph(const std::filesystem::path path)
{
    std::vector<std::string> filename_parts;
    boost::split(filename_parts, path.stem().string(), boost::is_any_of("_"));

    assert(filename_parts.size() == 3);
    this->congruence = filename_parts.at(0);
    this->group = filename_parts.at(1);
    this->size = filename_parts.at(2);
    this->identifier = path.extension().string().substr(2);
    this->nodes = std::stoi(this->size.substr(1));
}

void GraphCharacteristics::decompose_path_ground(const std::filesystem::path path)
{
    std::vector<std::string> filename_parts;
    boost::split(filename_parts, path.stem().string(), boost::is_any_of(FileIO::UNDERSCORE));

    assert(filename_parts.size() == 2);
    this->congruence = filename_parts.at(0);
    this->group = filename_parts.at(1);
}
