#include <iostream>
#include <armadillo>

int main() {

    std::cout << "Hello, from Graphiso-Extractor project" << std::endl;
    arma::mat matrix = arma::mat(4, 4, arma::fill::randu);
    matrix.print();
}
