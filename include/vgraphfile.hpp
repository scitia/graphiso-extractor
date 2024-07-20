#pragma once

#ifndef V_GRAPH_FILE_H
#define V_GRAPH_FILE_H

#include "gfile.hpp"
#include <armadillo>

class VGraphFile : public GFile
{
private:
    arma::umat matrix;
    int nodes;

public:
    VGraphFile(const std::filesystem::path path) : GFile(path){};
    // getters, setters
    const arma::umat get_matrix() const;
    const int get_nodes() const;
    void set_matrix(arma::umat matrix);
    void set_nodes(int nodes);
};

#endif //V_GRAPH_FILE_H