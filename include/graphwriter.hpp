#pragma once

#ifndef GRAPH_WRITER_H
#define GRAPH_WRITER_H

#include "graphfile.hpp"
#include "iwriteable.hpp"

class GraphWriter : public IWriteable
{
public:
    virtual bool write(GFile &file) const override;
private:
};

#endif //GRAPH_WRITER_H