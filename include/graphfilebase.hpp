#pragma once

#ifndef GRAPH_FILE_H
#define GRAPH_FILE_H

#include "filereader.hpp"

class GraphFileBase : public FileIO {

private:
    FileReader reader;

    std::string filename;
    std::string relative;
    std::string source_absolute;
    std::string target_absolute;
    std::string target_filename;
    std::string source_db_uri;
    std::string target_db_uri;

public:
    GraphFileBase(std::filesystem::path& path, const std::string source_db_uri, std::string target_db_uri);
    void to_string() const;

    // getters for instance
    const std::string get_filename() const;
    const std::string get_relative() const;
    const std::string get_source_absolute() const;
    const std::string get_target_absolute() const;
    const std::string get_target_filename() const;
    const std::string get_source_db_uri() const;
    const std::string get_target_db_uri() const;
    const FileReader get_reader() const;

    // setters
    void set_target_absolute(std::string target_absolute);
    void set_target_filename(std::string target_filename);
};

#endif //GRAPH_FILE_H