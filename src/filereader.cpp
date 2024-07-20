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

std::map<std::string, int> FileReader::read_text(const std::filesystem::path &path) const
{
    if (!std::filesystem::exists(path) || 
        !std::filesystem::is_regular_file(path) || 
        !path.has_extension() || 
        path.extension() != FileIO::GTR_EXTENSION) {
        throw std::runtime_error("Incorrect file path! " + path.string());
    }

    std::fstream fground_truth;

    std::map<std::string, int> gtr_key_value_map;

    fground_truth.open(path.string(), std::ios::in);
    if (fground_truth.is_open()) {
        std::string single_ground_truth;
        while(std::getline(fground_truth, single_ground_truth)) {
            std::vector<std::string> gtr;
            boost::split(gtr, single_ground_truth, boost::is_any_of(" "));
            assert(gtr.size() == 2);
            std::string graph_id = gtr.at(0);
            int congruent_elems = std::stoi(gtr.at(1));
            gtr_key_value_map.insert({graph_id, congruent_elems});
        }
        fground_truth.close(); 
    }

    return gtr_key_value_map;
}
