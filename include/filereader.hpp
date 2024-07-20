#pragma once

#ifndef FILE_READER_H
#define FILE_READER_H

#include "fileio.hpp"

class FileReader : public FileIO {

private:

public:
    std::string relative_path(const std::string path, const std::string base) const;
    std::string read_property(const std::string property_name) const;
    std::map<std::string, int> read_text(const std::filesystem::path &path) const;
};

#endif //FILE_READER_H