#pragma once
#pragma warning(disable:4996)

#ifndef GRAPH_IO_H
#define GRAPH_IO_H

#include <armadillo>
#include <exception>
#include "filereader.hpp"
#include "filewriter.hpp"
#include "graphfile.hpp"
#include "graphdata.hpp"

class GraphIO {

private:
    FileReader reader;
    FileWriter writer;

public:
    void do_preactions() const;
    void convert() const;

private:
	unsigned short read_word(FILE* in) const;
    GraphData read_graph(FILE* in) const;
    GraphData read_graph_file(FILE** in, std::string absolute_path) const;
};

#endif //GRAPH_IO_H