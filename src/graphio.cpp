#include "graphio.hpp"

void GraphIO::do_preactions() const
{
    std::string target_path = this->reader.read_property(FileIO::CONFIG_DB_TARGET);
    this->writer.create_required_directories(target_path);
}

void GraphIO::convert() const
{
    std::string source_path = this->reader.read_property(FileIO::CONFIG_DB_SOURCE);

    FILE* file_ptr;
    GraphData graph;

    for (const auto& entry : std::filesystem::recursive_directory_iterator(source_path)) {
        if (std::filesystem::is_regular_file(entry.path())) {

            std::filesystem::path path = entry.path();
            GraphFile ginfo = GraphFile(path);

            // read graph file
            graph = read_graph_file(&file_ptr, ginfo.get_source_absolute());

            // save graph adjacency matrix file
            graph.save_adjacency_matrix(ginfo.get_target_absolute());

            // TODO to implement
            // log the success of the operation on console
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

    for (i = 0; i < nodes; i++)
    {
        edges = read_word(in);

        for (j = 0; j < edges; j++)
        {
            target = read_word(in);
            matrix.at(i, target) = 1;
        }
    }

    return GraphData(nodes, matrix);
}

GraphData GraphIO::read_graph_file(FILE **in, std::string absolute_path) const
{
    try {
	    *in = fopen(absolute_path.c_str(), "rb"); // file is opening in read binary mode
        if (in == NULL) {
            throw std::runtime_error("file cannot be opened");
        }
        else {
            return read_graph(*in);
        }
    }
    catch (std::ifstream::failure e) {
        std::cerr << "error during reading the file under path: " << absolute_path << std::endl;
        throw std::runtime_error(e.what());
    }
}
