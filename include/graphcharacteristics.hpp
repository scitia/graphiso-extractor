#pragma once

#ifndef GRAPH_CHARACTERISTICS_H
#define GRAPH_CHARACTERISTICS_H

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

public:
    // constructors
    GraphCharacteristics();
    GraphCharacteristics(const std::filesystem::path filepath);

    // getters
    const std::string get_congruence() const;
    const std::string get_group() const;
    const std::string get_size() const;
    const std::string get_identifier() const;

    // setters
    void set_congruence(const std::string congruence);
    void set_group(const std::string group);
    void set_size(const std::string size);
    void set_identifier(const std::string identifier);

private:
    void decompose_path(const std::filesystem::path path);
};

#endif //GRAPH_CHARACTERISTICS_H