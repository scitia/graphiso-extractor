#include "fileio.hpp"

const std::string FileIO::APP_TITLE = R"(
                          __    ____ ____ ____ 
  ___ _ ____ ___ _ ___   / /   /  _// __// __ \
 / _ `// __// _ `// _ \ / _ \ _/ / _\ \ / /_/ /
 \_, //_/   \_,_// .__//_//_//___//___/ \____/ 
/___/           /_/                            
)";
const std::string FileIO::WINDOWS_SEPARATOR = "\\";
const std::string FileIO::UNIX_SEPARATOR = "/";

const std::string FileIO::CONFIG_FILE_PATH = "../config.ini";

const std::string FileIO::CONFIG_DB_SOURCE = "database.source";
const std::string FileIO::CONFIG_DB_TARGET = "database.target";
const std::string FileIO::CONFIG_DB_GROUND = "database.ground";

const std::string FileIO::TXT_EXTENSION = ".txt";
const std::string FileIO::CSV_EXTENSION = ".csv";
const std::string FileIO::GTR_EXTENSION = ".gtr";
const std::string FileIO::UNDERSCORE = "_";
const std::string FileIO::SPACE = " ";

const char* FileIO::READ_BINARY = "rb";
const char* FileIO::SPLIT_REGEX = "_.";

const std::string FileIO::FIRST_FROM_PAIR = "A";
const std::string FileIO::SECOND_FROM_PAIR = "B";
const std::string FileIO::DEFAULT_BASE_FILENAME = "bgs"; // base graph structure
const std::string FileIO::DEFAULT_CONGRUENT_FILENAME = "cgs"; // congruent graph structure
const std::string FileIO::DEFAULT_GROUND_FILENAME = "gtr"; // ground-truth file