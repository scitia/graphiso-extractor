#pragma once

#ifndef GRAPH_FILE_H
#define GRAPH_FILE_H

#include "gfile.hpp"
#include "filesystemutils.hpp"
#include <armadillo>

class GraphFile : public GFile
{
private:
    arma::umat matrix;
    int nodes;

public:
    GraphFile(){};
    GraphFile(const std::filesystem::path path) : GFile(path){};

    virtual void build_target_absolute(const ResourceLocation resource) override;
    virtual std::string build_target_filename() const override;
    const arma::umat get_matrix() const;
    const int get_nodes() const;
    void set_matrix(arma::umat matrix);
    void set_nodes(int nodes);
};

#endif //GRAPH_FILE_H