#pragma once

#ifndef GRAPH_FILE_DETAILS
#define GRAPH_FILE_DETAILS

#include "graphfilebase.hpp"
#include <boost/algorithm/string.hpp>

class GraphFile : public GraphFileBase {

private:
    std::string congruence;
    std::string group;
    std::string size_group;
    std::string ordinal;
    std::string pair_label;
    std::string pair_id;

public:
    GraphFile(std::filesystem::path& path, const std::string source_db_uri, const std::string target_db_uri);
    const std::string build_target_absolute() const;

    // getters
    const std::string get_congruence() const;
    const std::string get_group() const;
    const std::string get_size_group() const;
    const std::string get_ordinal() const;
    const std::string get_pair_label() const;
    const std::string get_pair_id() const;

private:
    void set_pair_characteristics();
};

#endif //GRAPH_FILE_DETAILS