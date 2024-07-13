#pragma once

#ifndef FILE_IO_H
#define FILE_IO_H

#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <map>
#include <boost/algorithm/string/join.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

class FileIO {

private:

public:

    // platform specific constants
    static const std::string WINDOWS_SEPARATOR;

    // configuration file name
    static const std::string CONFIG_FILE_PATH;

    // defined config.ini properties
    static const std::string CONFIG_DB_SOURCE;
    static const std::string CONFIG_DB_TARGET;

    // extensions, separators, etc.
    static const std::string CSV_EXTENSION;
    static const std::string UNDERSCORE;
};

#endif //FILE_IO_H