#include "graphfile.hpp"

void GraphFile::validate() const
{
    assert(this->get_matrix().n_cols == this->get_matrix().n_rows);
    assert(this->get_characteristics().get_nodes() == this->get_matrix().n_rows);
}

void GraphFile::build_target_absolute()
{
    std::filesystem::path resource_target = this->get_resource().get_target();
    std::filesystem::path resource_source = this->get_resource().get_source();

    std::string base_path = resource_target.string();

    std::string target_path = base_path
        .append(FileIO::UNIX_SEPARATOR)
        .append(this->relative_toward(resource_source).string())
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

std::string GraphFile::build_target_filename() const
{
    std::string graph_label = std::string{this->get_path().filename().extension().string().at(1)};
    return FileIO::FIRST_FROM_PAIR == graph_label ? FileIO::DEFAULT_GA_FILENAME : FileIO::DEFAULT_GB_FILENAME;
}

const arma::umat GraphFile::get_matrix() const
{
    return this->matrix;
}

const int GraphFile::get_nodes() const
{
    return this->nodes;
}

void GraphFile::set_matrix(arma::umat matrix)
{
    this->matrix = std::move(matrix);
}

void GraphFile::set_nodes(int nodes)
{
    this->nodes = std::move(nodes);
}
