#include "graphwriter.hpp"

bool GraphWriter::write(GFile &file) const
{
    VGraphFile* graph = dynamic_cast<VGraphFile*>(&file);
    std::string target = std::filesystem::absolute(graph->get_target_path()).string(); // problem
    bool save_result = graph->get_matrix().save(arma::csv_name(target));
    delete graph;
    return save_result;
}
