#pragma once

#ifndef G_READER_H
#define G_READER_H

#include "ireadable.hpp"
#include <cassert>
#include <memory>

class GReader
{
private:
    std::unique_ptr<IReadable> gcontext;
public:
    explicit GReader(std::unique_ptr<IReadable> &&gcontext = {}) : gcontext(std::move(gcontext)){};
    void set_context(std::unique_ptr<IReadable> &&gcontext);
    GFile read(GFile &file) const;
};


#endif //G_READER_H