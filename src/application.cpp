#include "application.hpp"

void Application::run()
{
    GraphIO graphio;
    graphio.preactions();
    graphio.convert();
    graphio.postactions();
}
