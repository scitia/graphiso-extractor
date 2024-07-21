#pragma once

#ifndef G_READER_H
#define G_READER_H

#include "ireadable.hpp"
#include <cassert>
#include <memory>

/*

explicit Context(std::unique_ptr<Strategy> &&strategy = {}) : strategy_(std::move(strategy))
void set_strategy(std::unique_ptr<Strategy> &&strategy)

*/

class GReader
{
private:
    std::unique_ptr<IReadable> context;
    // IReadable* gcontext;
public:
    // GReader(){};
    // explicit GReader(std::unique_ptr<IReadable> &&context = {}) : context(std::move(context)){};
    void set_context(std::unique_ptr<IReadable> &&context);
    // GReader(IReadable &gcontext);
    // void set_context(IReadable &gcontext);
    GFile* read(GFile &file) const;
};

#endif //G_READER_H