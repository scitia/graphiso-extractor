#include "groundreader.hpp"

GFile* GroundReader::read(GFile &file) const
{
    std::fstream ground_file_stream;
    std::map<std::string, int> ground_content;

    std::string ground_filename = std::filesystem::absolute(file.get_path()).string();
    
    ground_file_stream.open(ground_filename, std::ios::in);
    if (ground_file_stream.is_open()) {
        
        std::string current_line;
        while (std::getline(ground_file_stream, current_line)) {
            ground_content.insert(parse_adjacenty(current_line));
        }

        ground_file_stream.close();
    }

    GroundFile* ground = dynamic_cast<GroundFile*>(&file);
    ground->set_adjacencies(ground_content);
    return ground;
}

std::pair<std::string, int> GroundReader::parse_adjacenty(std::string line) const
{
    std::vector<std::string> filename_value;
    boost::split(filename_value, line, boost::is_space());

    assert(filename_value.size() == 2);

    std::string filename = filename_value.at(0);
    int value = std::stoi(filename_value.at(1));

    return std::make_pair(filename, value);
}
