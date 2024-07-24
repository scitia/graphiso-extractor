#include "groundfile.hpp"

void GroundFile::build_target_absolute()
{
    // std::string base_path = resource.get_target().string();
    std::filesystem::path resource_target = this->get_resource().get_target();
    std::filesystem::path resource_source = this->get_resource().get_ground();
    std::string s_resource_target = std::filesystem::absolute(this->get_resource().get_target()).string();
    std::string s_resource_source = std::filesystem::absolute(this->get_resource().get_source()).string();
    std::string s_parent_path = std::filesystem::absolute(this->get_path().parent_path()).string();

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

    // std::string target_filename = build_target_filename();

    // target_path
    //     .append(FileIO::UNIX_SEPARATOR)
    //     .append(target_filename);

    // std::filesystem::path tp = std::filesystem::path(target_path);
    this->set_target_path(target_path);
}

std::string GroundFile::build_target_filename() const
{
    return "ground.txt";
}

const std::map<std::string, int> GroundFile::get_adjacencies() const
{
    return this->adjacencies;
}

void GroundFile::set_adjacencies(std::map<std::string, int> adjacencies)
{
    this->adjacencies = std::move(adjacencies);
}
