#pragma once

#ifndef G_READER_H
#define G_READER_H

#include "ireadable.hpp"
#include <cassert>
#include <memory>

class GReader
{
private:
    IReadable* gcontext;
public:
    GReader(){};
    GReader(IReadable &gcontext);
    void set_context(IReadable &gcontext);
    GFile* read(GFile &file) const;
};

#endif //G_READER_H