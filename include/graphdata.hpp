#pragma once

#ifndef GRAPH_DATA_H
#define GRAPH_DATA_H

#include <armadillo>
#include <string>

class GraphData {

private:
    int nodes;
    arma::umat amatrix;

public:
    GraphData() {};
    GraphData(int nodes, arma::umat amatrix) : nodes(nodes), amatrix(amatrix) {};
    void save_adjacency_matrix(const std::string target_path) const;

    // getters
    const int get_nodes() const;
    const arma::umat get_amatrix() const;

};

#endif //GRAPH_DATA_H