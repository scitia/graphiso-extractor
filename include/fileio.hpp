#pragma once

#ifndef FILE_IO_H
#define FILE_IO_H

#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <map>
#include <cassert>
#include <boost/algorithm/string/join.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

class FileIO {

private:

public:

    // platform specific constants
    static const std::string WINDOWS_SEPARATOR;
    static const std::string UNIX_SEPARATOR;

    // configuration file name
    static const std::string CONFIG_FILE_PATH;

    // defined config.ini properties
    static const std::string CONFIG_DB_SOURCE;
    static const std::string CONFIG_DB_TARGET;

    // extensions, separators, etc.
    static const std::string CSV_EXTENSION;
    static const std::string UNDERSCORE;

    // file handling constants
    static const char* READ_BINARY;
    static const char* SPLIT_REGEX;

    // graph files specific constants
    static const std::string FIRST_FROM_PAIR;
    static const std::string SECOND_FROM_PAIR;
};

#endif //FILE_IO_H