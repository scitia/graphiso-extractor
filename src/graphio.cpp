#include "graphio.hpp"

const int GraphIO::ALL_GRAPH_AMOUNT = 145600;

GraphIO::GraphIO()
{
    this->source_db_uri = this->reader.read_property(FileIO::CONFIG_DB_SOURCE);
    this->target_db_uri = this->reader.read_property(FileIO::CONFIG_DB_TARGET);
    this->ground_uri = std::filesystem::path(this->reader.read_property(FileIO::CONFIG_DB_GROUND));
}

void GraphIO::preactions() const
{
    this->writer.create_required_directories(this->target_db_uri);
}

void GraphIO::postactions() const
{
    // GTR Files 
}

void GraphIO::convert() const
{
    GraphData graph;
    int counter = 0;

    for (const auto& entry : std::filesystem::recursive_directory_iterator(this->source_db_uri)) {
        if (std::filesystem::is_regular_file(entry.path())) {

            std::filesystem::path path = entry.path();
            GraphFile ginfo = GraphFile(path, this->source_db_uri, this->target_db_uri);
            
            try {
                graph = read_graph_file(ginfo.get_source_absolute());
                graph.save_adjacency_matrix(ginfo.get_target_absolute());
                ++counter;
                std::string processing_info = "Processed graph " + std::to_string(counter) + "/" + std::to_string(this->ALL_GRAPH_AMOUNT);
                BOOST_LOG_TRIVIAL(info) << processing_info;
            } catch (std::exception ex) {
                BOOST_LOG_TRIVIAL(error) << "An error occured during processing graph file";
                BOOST_LOG_TRIVIAL(error) << ex.what();
                ginfo.to_string();
            }
        }
    }
}

unsigned short GraphIO::read_word(FILE *in) const
{
    unsigned char b1, b2;
    b1 = getc(in);
    b2 = getc(in);
    return b1 | (b2 << 8);
}

GraphData GraphIO::read_graph(FILE *in) const
{
    int nodes;
    int edges;
    int target;
    int i, j;

    nodes = read_word(in);
    arma::umat matrix(nodes, nodes, arma::fill::zeros);

    for(i=0; i<nodes; i++)
    { 
        edges=read_word(in);
        for(j=0; j<edges; j++) { 
            target = read_word(in);
            matrix(i,target) = 1;
        }
    }

    return GraphData(nodes, matrix);
}

GraphData GraphIO::read_graph_file(std::string absolute_path) const
{
    FILE* in = fopen(absolute_path.c_str(), FileIO::READ_BINARY);
    
    if (in == NULL) {
        throw std::runtime_error("File not found exception");
    }

    try {
        GraphData graph = read_graph(in);
        fclose(in);
        return graph;
    } catch(...) {
        fclose(in);
        throw;
    }
}
