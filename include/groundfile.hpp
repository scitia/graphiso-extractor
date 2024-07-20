#pragma once

#ifndef GROUND_FILE_H
#define GROUND_FILE_H

#include "gfile.hpp"
#include <map>

class GroundFile : public GFile
{
private:
    std::map<std::string, int> adjacencies;

public:
    GroundFile(const std::filesystem::path path); 
};


#endif //GROUND_FILE_H