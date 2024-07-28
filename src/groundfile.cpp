#include "groundfile.hpp"

void GroundFile::validate() const
{
    assert(!this->adjacencies.empty());
}

void GroundFile::build_target_absolute()
{
    std::filesystem::path resource_target = this->get_resource().get_target();
    std::filesystem::path resource_source = this->get_resource().get_ground();

    std::string relative_path = this->relative_toward(resource_source).string();

    std::filesystem::path target_path = std::filesystem::path(
        resource_target.string()
        .append(FileIO::UNIX_SEPARATOR)
        .append(relative_path)
        .append(FileIO::UNIX_SEPARATOR)
        .append(this->get_characteristics().get_size())
        .append(FileIO::UNIX_SEPARATOR)
        .append(this->get_characteristics().get_identifier())
        .append(FileIO::UNIX_SEPARATOR)
        .append(build_target_filename())
    );

    this->set_target_path(target_path);
}

std::string GroundFile::build_target_filename() const
{
    return FileIO::DEFAULT_GROUND_FILENAME;
}

const std::map<std::string, int> GroundFile::get_adjacencies() const
{
    return this->adjacencies;
}

void GroundFile::set_adjacencies(std::map<std::string, int> adjacencies)
{
    this->adjacencies = std::move(adjacencies);
}
