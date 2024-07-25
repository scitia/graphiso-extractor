#pragma once

#ifndef FILE_IO_H
#define FILE_IO_H

#include <iostream>
#include <string>
#include <filesystem>
#include <vector>
#include <map>
#include <cassert>
#include <fstream>
#include <boost/algorithm/string/join.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

class FileIO {

private:

public:

    static const std::string APP_TITLE;
    // platform specific constants
    static const std::string WINDOWS_SEPARATOR;
    static const std::string UNIX_SEPARATOR;

    // configuration file name
    static const std::string CONFIG_FILE_PATH;

    // defined config.ini properties
    static const std::string CONFIG_DB_SOURCE;
    static const std::string CONFIG_DB_TARGET;
    static const std::string CONFIG_DB_GROUND;

    // extensions, separators, etc.
    static const std::string TXT_EXTENSION;
    static const std::string CSV_EXTENSION;
    static const std::string GTR_EXTENSION;
    static const std::string UNDERSCORE;
    static const std::string SPACE;

    // file handling constants
    static const char* READ_BINARY;
    static const char* SPLIT_REGEX;

    // graph files specific constants
    static const std::string FIRST_FROM_PAIR;
    static const std::string SECOND_FROM_PAIR;

    static const std::string DEFAULT_GROUND_FILENAME;
    static const std::string DEFAULT_BASE_FILENAME;
    static const std::string DEFAULT_CONGRUENT_FILENAME;
};

#endif //FILE_IO_H