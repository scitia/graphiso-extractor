#pragma once

#ifndef I_READABLE_H
#define I_READABLE_H

#include "gfile.hpp"

class IReadable
{
public:
    virtual ~IReadable() = default;
    virtual GFile read(GFile &file) = 0;
};


#endif //I_READABLE_H