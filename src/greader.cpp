#include "greader.hpp"

// GReader::GReader(IReadable &gcontext)
// {
//     this->gcontext = &gcontext;
// }

// void GReader::set_context(IReadable &gcontext)
// {
//     this->gcontext = &gcontext;
// }

void GReader::set_context(std::unique_ptr<IReadable> &&context)
{
    this->context = std::move(context);
}

GFile *GReader::read(GFile &file) const
{
    assert(context);
    return context->read(file);
}
