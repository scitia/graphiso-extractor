#include "groundreader.hpp"

GFile* GroundReader::read(GFile &file)
{
    return new GroundFile();
}
