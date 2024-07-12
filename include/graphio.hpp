#pragma once

#ifndef GRAPH_IO_H
#define GRAPH_IO_H

#include "filereader.hpp"
#include "filewriter.hpp"

class GraphIO {

private:
    FileReader reader;
    FileWriter writer;

public:
    void generate_name(const std::string old_filename) const;
    void convert() const;
 
};

#endif //GRAPH_IO_H