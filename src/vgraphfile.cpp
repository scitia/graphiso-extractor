#include "vgraphfile.hpp"

void VGraphFile::build_target_absolute(const ResourceLocation resource)
{
    std::string base_path = resource.get_target().string();

    std::string target_path = base_path
        .append(FileIO::UNIX_SEPARATOR)
        .append(this->relative_toward(resource.get_source()).string())
        .append(FileIO::UNIX_SEPARATOR)
        .append(this->get_characteristics().get_size())
        .append(FileIO::UNIX_SEPARATOR)
        .append(this->get_characteristics().get_identifier());
    
    FilesystemUtils::create_directories(std::filesystem::path(target_path));

    std::string target_filename = build_target_filename();

    target_path
        .append(FileIO::UNIX_SEPARATOR)
        .append(target_filename);

    std::filesystem::path tp = std::filesystem::path(target_path);
    this->set_target_path(tp);
}

std::string VGraphFile::build_target_filename() const
{
    std::vector<std::string> filename_parts = {
        this->get_characteristics().get_congruence(),
        this->get_characteristics().get_group(),
        this->get_characteristics().get_size(),
        this->get_path().filename().extension().string().substr(1)
    };

    return boost::algorithm::join(filename_parts, FileIO::UNDERSCORE).append(FileIO::CSV_EXTENSION);
}

const arma::umat VGraphFile::get_matrix() const
{
    return this->matrix;
}

const int VGraphFile::get_nodes() const
{
    return this->nodes;
}

void VGraphFile::set_matrix(arma::umat matrix)
{
    this->matrix = std::move(matrix);
}

void VGraphFile::set_nodes(int nodes)
{
    this->nodes = std::move(nodes);
}
