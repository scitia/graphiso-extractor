#include "filereader.hpp"

std::string FileReader::relative_path(const std::string path, const std::string base) const
{
    return path.substr(base.length());
}

std::string FileReader::read_property(const std::string property_name) const
{
    boost::property_tree::ptree property_tree;

    try {
        boost::property_tree::ini_parser::read_ini(CONFIG_FILE_PATH, property_tree);
    }
    catch (const boost::property_tree::ini_parser_error& ex) {
        std::cerr << "Error reading INI file: " << ex.what() << std::endl;
        throw ex;
    }

    return property_tree.get<std::string>(property_name);
}
