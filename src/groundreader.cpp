#include "groundreader.hpp"

GFile* GroundReader::read(GFile &file) const
{
    return new GroundFile();
}
