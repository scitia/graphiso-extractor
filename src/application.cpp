#include "application.hpp"

void Application::run()
{
    GraphIO graphio;
    graphio.do_preactions();
    graphio.convert();
}
