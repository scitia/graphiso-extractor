#include "greader.hpp"

void GReader::set_context(std::unique_ptr<IReadable> &&context)
{
    this->context = std::move(context);
}

GFile *GReader::read(GFile &file) const
{
    assert(context);
    return context->read(file);
}
