#include "gwriter.hpp"

void GWriter::set_context(std::unique_ptr<IWriteable> &&context)
{
    this->context = std::move(context);
}

bool GWriter::write(GFile &file) const
{
    assert(this->context);
    return this->context->write(file);
}
