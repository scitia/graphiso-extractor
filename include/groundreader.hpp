#pragma once

#ifndef GRAOUND_READER_H
#define GRAOUND_READER_H

#include "fileio.hpp"
#include "ireadable.hpp"
#include "groundfile.hpp"
#include <boost/algorithm/string.hpp>
#include <fstream>
#include <iostream>
#include <utility>
#include <string>

class GroundReader : public IReadable
{
public:
    virtual GFile* read(GFile &file) const;
private:
    std::pair<std::string, int> parse_adjacenty(std::string line) const;
};

#endif //GRAOUND_READER_H