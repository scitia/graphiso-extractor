#pragma once
#pragma warning(disable:4996)

#ifndef GRAPH_IO_H
#define GRAPH_IO_H

#include <armadillo>
#include <exception>
#include <boost/log/trivial.hpp>
#include "filereader.hpp"
#include "filewriter.hpp"
#include "graphfile.hpp"
#include "graphdata.hpp"

class GraphIO {

private:
    FileReader reader;
    FileWriter writer;
    std::string source_db_uri; // in the future change type to std::filesystem::path
    std::string target_db_uri; // in the future change type to std::filesystem::path
    std::filesystem::path ground_uri;

public:

    static const int ALL_GRAPH_AMOUNT;

    GraphIO();
    void preactions() const;
    void postactions() const;
    void convert() const;

public:
	unsigned short read_word(FILE* in) const;
    GraphData read_graph(FILE* in) const;
    GraphData read_graph_file(std::string absolute_path) const;
};

#endif //GRAPH_IO_H