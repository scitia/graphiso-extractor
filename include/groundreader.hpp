#pragma once

#ifndef GRAOUND_READER_H
#define GRAOUND_READER_H

#include "ireadable.hpp"
#include "groundfile.hpp"

class GroundReader : public IReadable
{
public:
    virtual GFile* read(GFile &file) const;
private:
};

#endif //GRAOUND_READER_H