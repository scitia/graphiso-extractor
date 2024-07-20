#pragma once

#ifndef GRAOUND_READER_H
#define GRAOUND_READER_H

#include "ireadable.hpp"

class GroundReader : public IReadable
{
public:
    virtual GFile read(GFile &file);
private:
};


#endif //GRAOUND_READER_H