#include "application.hpp"

void Application::run()
{
    GraphConverter converter;
    converter.initially();
    converter.preactions();
    converter.convert();
    converter.postactions();
    converter.healthcheck();
    converter.finally();
}
