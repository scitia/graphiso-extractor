#pragma once

#ifndef GRAPH_IO_H
#define GRAPH_IO_H

#include <armadillo>
#include "filereader.hpp"
#include "filewriter.hpp"
#include "graphfile.hpp"

class GraphIO {

private:
    FileReader reader;
    FileWriter writer;

public:
    void convert() const;
};

#endif //GRAPH_IO_H