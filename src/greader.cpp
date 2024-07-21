#include "greader.hpp"

GReader::GReader(IReadable &gcontext)
{
    this->gcontext = &gcontext;
}

void GReader::set_context(IReadable &gcontext)
{
    this->gcontext = &gcontext;
}

GFile* GReader::read(GFile &file) const
{
    return gcontext->read(file);
}
