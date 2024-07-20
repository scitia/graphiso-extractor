#include "graphwriter.hpp"

bool GraphWriter::write(GFile &file) const
{
    VGraphFile* graph = dynamic_cast<VGraphFile*>(&file);
    bool save_result = graph->get_matrix().save(arma::csv_name(""));
    delete graph;
    return save_result;
}
