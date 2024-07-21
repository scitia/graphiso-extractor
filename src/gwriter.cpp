#include "gwriter.hpp"

GWriter::GWriter(std::unique_ptr<IWriteable> &gcontext)
{
    this->gcontext = std::move(gcontext);
}

void GWriter::set_context(std::unique_ptr<IWriteable> &gcontext)
{
    this->gcontext = std::move(gcontext);
}

bool GWriter::write(GFile &file) const
{
    assert(this->gcontext);
    return this->gcontext->write(file);
}
