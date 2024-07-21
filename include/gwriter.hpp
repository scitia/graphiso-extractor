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
    std::unique_ptr<IWriteable> context;
public:
    void set_context(std::unique_ptr<IWriteable> &&context);
    bool write(GFile &file) const;
};


#endif //G_WRITER_H