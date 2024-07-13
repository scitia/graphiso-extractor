#include "graphdata.hpp"

void GraphData::save_adjacency_matrix(const std::string target_path) const
{
    this->amatrix.save(arma::csv_name(target_path));
}

const int GraphData::get_nodes() const
{
    return this->nodes;
}

const arma::umat GraphData::get_amatrix() const
{
    return this->amatrix;
}
