#include "fileio.hpp"

const std::string FileIO::WINDOWS_SEPARATOR = "\\";
const std::string FileIO::UNIX_SEPARATOR = "/";

const std::string FileIO::CONFIG_FILE_PATH = "../config.ini";

const std::string FileIO::CONFIG_DB_SOURCE = "database.source";
const std::string FileIO::CONFIG_DB_TARGET = "database.target";

const std::string FileIO::CSV_EXTENSION = ".csv";
const std::string FileIO::UNDERSCORE = "_";

const char* FileIO::READ_BINARY = "rb";
const char* FileIO::SPLIT_REGEX = "_.";

const std::string FileIO::FIRST_FROM_PAIR = "A";
const std::string FileIO::SECOND_FROM_PAIR = "B";