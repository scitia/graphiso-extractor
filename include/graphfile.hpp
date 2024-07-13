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

public:
    GraphFile(std::filesystem::path& path);
    const std::string build_target_absolute() const;
};

#endif //GRAPH_FILE_DETAILS