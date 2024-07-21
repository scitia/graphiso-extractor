#pragma once

#ifndef GROUND_WRITER_H
#define GROUND_WRITER_H

#include "iwriteable.hpp"

class GroundWriter : public IWriteable
{
public:
    virtual bool write(GFile &file) const override;
};

#endif //GROUND_WRITER_H