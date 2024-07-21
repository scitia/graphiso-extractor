#pragma once

#ifndef INI_READER_H
#define INI_READER_H

#include "fileio.hpp"

class INIReader { 
public:
    std::string read_property(const std::string property_name) const;
};

#endif //INI_READER_H