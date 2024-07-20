#include "graphreader.hpp"

GFile GraphReader::read(GFile &file)
{
    FILE* in = fopen(file.absolute().string().c_str(), "rb");
    
    if (in == NULL) {
        throw std::runtime_error("File not found exception");
    }

    try {
        VGraphFile* graph = dynamic_cast<VGraphFile*>(&file); 
        read_graph(in, *graph);
        fclose(in);
        return *graph;
    } catch(...) {
        fclose(in);
        throw;
    }
}

unsigned short GraphReader::read_word(FILE *in) const
{
    unsigned char b1, b2;
    b1 = getc(in);
    b2 = getc(in);
    return b1 | (b2 << 8);
}

void GraphReader::read_graph(FILE *in, VGraphFile &file) const
{
    int nodes, edges, target;

    nodes = read_word(in);
    arma::umat matrix(nodes, nodes, arma::fill::zeros);

    for(int i = 0; i<nodes; i++)
    { 
        edges=read_word(in);
        for(int j = 0; j<edges; j++) { 
            target = read_word(in);
            matrix(i,target) = 1;
        }
    }

    file.set_matrix(matrix);
    file.set_nodes(nodes);

    // return file;
}
