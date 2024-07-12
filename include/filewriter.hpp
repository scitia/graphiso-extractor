#pragma once

#ifndef FILE_WRITER_H
#define FILE_WRITER_H

#include "fileio.hpp"

class FileWriter : public FileIO {

private:

public:
    void create_directory(const std::string &parent_path, const std::string &directory_name);
    void create_required_directories(const std::string& target_path);
};

#endif //FILE_WRITER_H