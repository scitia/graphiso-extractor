#pragma once

#ifndef GRAPH_READER_H
#define GRAPH_READER_H

#include "ireadable.hpp"
#include "vgraphfile.hpp"
#include "vgraphfile.hpp"
#include <memory>

class GraphReader : public IReadable
{
public:
    virtual GFile* read(GFile &file);
private:
    unsigned short read_word(FILE* in) const;
    void read_graph(FILE* in, VGraphFile &file) const;
};

#endif //GRAPH_READER_H