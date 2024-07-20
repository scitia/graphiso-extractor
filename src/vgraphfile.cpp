#include "vgraphfile.hpp"

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
