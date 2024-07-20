#include "application.hpp"

void Application::run()
{
    // old version
    // GraphIO graphio;
    // graphio.preactions();
    // graphio.convert();
    // graphio.postactions();

    GraphConverter converter;
    converter.preactions();
    converter.convert();
    converter.postactions();
}
