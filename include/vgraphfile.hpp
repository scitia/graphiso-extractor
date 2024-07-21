#pragma once

#ifndef V_GRAPH_FILE_H
#define V_GRAPH_FILE_H

#include "gfile.hpp"
#include "filesystemutils.hpp"
#include "itargetable.hpp"
#include <armadillo>

class VGraphFile : public GFile
{
private:
    arma::umat matrix;
    int nodes;

public:
    VGraphFile(){};
    VGraphFile(const std::filesystem::path path) : GFile(path){};

    virtual void build_target_absolute(const ResourceLocation resource) override;
    virtual std::string build_target_filename() const override;
    const arma::umat get_matrix() const;
    const int get_nodes() const;
    void set_matrix(arma::umat matrix);
    void set_nodes(int nodes);
};

#endif //V_GRAPH_FILE_H