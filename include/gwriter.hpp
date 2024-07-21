#pragma once

#ifndef G_WRITER_H
#define G_WRITER_H

#include "iwriteable.hpp"
#include "gfile.hpp"
#include <memory>
#include <cassert>

class GWriter
{
private:
    std::unique_ptr<IWriteable> gcontext;
public:
    GWriter(){};
    GWriter(std::unique_ptr<IWriteable> &gcontext);
    void set_context(std::unique_ptr<IWriteable> &gcontext);
    bool write(GFile &file) const;
};


#endif //G_WRITER_H