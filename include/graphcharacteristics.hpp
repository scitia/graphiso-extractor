#pragma once

#ifndef GRAPH_CHARACTERISTICS_H
#define GRAPH_CHARACTERISTICS_H

#include "fileio.hpp"
#include <vector>
#include <cassert>
#include <filesystem>
#include <boost/algorithm/string.hpp>
#include <string>

class GraphCharacteristics
{
private:
    std::string congruence;
    std::string group;
    std::string size;
    std::string identifier;
    int nodes;

public:
    // constructors
    GraphCharacteristics();
    GraphCharacteristics(const std::filesystem::path filepath);

    // getters
    const std::string get_congruence() const;
    const std::string get_group() const;
    const std::string get_size() const;
    const std::string get_identifier() const;
    const int get_nodes() const;

    // setters
    void set_congruence(const std::string congruence);
    void set_group(const std::string group);
    void set_size(const std::string size);
    void set_identifier(const std::string identifier);
    void set_nodes(const int nodes);

private:
    void decompose_path(const std::filesystem::path path);
    void decompose_path_graph(const std::filesystem::path path);
    void decompose_path_ground(const std::filesystem::path path);
};

#endif //GRAPH_CHARACTERISTICS_H