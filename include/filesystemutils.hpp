#pragma once

#ifndef FILESYSTEM_UTILS_H
#define FILESYSTEM_UTILS_H

#include "fileio.hpp"
#include <filesystem>
#include <string>

class FilesystemUtils
{  
public:
    static bool create_directory(std::filesystem::path path, std::string directory_name);
    static bool create_directories(std::filesystem::path path);
};


#endif //FILESYSTEM_UTILS_H