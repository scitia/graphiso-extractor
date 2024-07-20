#pragma once

#ifndef GRAPH_CONVERTER_H
#define GRAPH_CONVERTER_H

#include "groundfile.hpp"
#include "vgraphfile.hpp"
#include "greader.hpp"
#include "gwriter.hpp"
#include "graphreader.hpp"
#include "graphwriter.hpp"
#include "groundreader.hpp"
#include "groundwriter.hpp"
#include "filesystemutils.hpp"
#include "filereader.hpp"
#include <boost/log/trivial.hpp>
#include <filesystem>
#include <functional>

class GraphConverter
{
private:
    GReader reader;
    GWriter writer;
    FileReader config;
    FilesystemUtils fs_utils;
    std::filesystem::path source_db_uri;
    std::filesystem::path target_db_uri;
    std::filesystem::path ground_db_uri;

public:
    GraphConverter();
    void preactions() const;
    void postactions();
    void convert();
private:
    void base_procedure(std::filesystem::path path, std::function<void(std::filesystem::path path)> procedure);
    void create_required_directories(std::filesystem::path path) const;
};


#endif //GRAPH_CONVERTER_H