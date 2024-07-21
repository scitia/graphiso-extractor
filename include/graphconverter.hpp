#pragma once

#ifndef GRAPH_CONVERTER_H
#define GRAPH_CONVERTER_H

#include "groundfile.hpp"
#include "graphfile.hpp"
#include "greader.hpp"
#include "gwriter.hpp"
#include "graphreader.hpp"
#include "graphwriter.hpp"
#include "groundreader.hpp"
#include "groundwriter.hpp"
#include "resourcelocation.hpp"
#include "filesystemutils.hpp"
#include "inireader.hpp"
#include <boost/log/trivial.hpp>
#include <filesystem>
#include <functional>

class GraphConverter
{
private:
    GReader reader;
    GWriter writer;
    INIReader config;
    ResourceLocation resource;

public:
    GraphConverter();
    void preactions() const;
    void postactions();
    void convert();
private:
    void create_required_directories(std::filesystem::path path) const;
};

#endif //GRAPH_CONVERTER_H