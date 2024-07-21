#pragma once

#ifndef GRAPH_READER_H
#define GRAPH_READER_H

#include "ireadable.hpp"
#include "graphfile.hpp"
#include <memory>

class GraphReader : public IReadable
{
public:
    virtual GFile* read(GFile &file) const;
private:
    unsigned short read_word(FILE* in) const;
    void read_graph(FILE* in, GraphFile &file) const;
};

#endif //GRAPH_READER_H