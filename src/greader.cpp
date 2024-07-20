#include "greader.hpp"

void GReader::set_context(std::unique_ptr<IReadable> &&gcontext)
{
    gcontext = std::move(gcontext);
}

GFile GReader::read(GFile &file) const
{
    assert(gcontext);
    return gcontext->read(file);
}
