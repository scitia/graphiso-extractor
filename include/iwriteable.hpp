#pragma once

#ifndef I_WRITEABLE_H
#define I_WRITEABLE_H

#include "gfile.hpp"

class IWriteable
{
public:
    virtual ~IWriteable() = default;
    virtual bool write(GFile &file) const = 0;
};

#endif //I_WRITEABLE_H