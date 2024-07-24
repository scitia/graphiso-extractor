#include "groundwriter.hpp"

bool GroundWriter::write(GFile &file) const
{
    GroundFile* ground = dynamic_cast<GroundFile*>(&file);

    std::map<std::string, int> adjacencies = ground->get_adjacencies();
    assert(!adjacencies.empty()); // this code should be moved to abstact validate method

    for (const auto& [filename, adj_amount] : ground->get_adjacencies()) {
        set_details(*ground, filename);
        std::string target_path = std::filesystem::absolute(ground->get_target_path()).string();
        write_single_ground(target_path, adj_amount);
    }

    delete ground;
    return true;
}

void GroundWriter::set_details(GroundFile &file, std::string filename) const
{
    // prepare method set characteristics
    std::pair<std::string, std::string> decomposed = decompose_filename(filename);
    GraphCharacteristics temp_characteristics = file.get_characteristics();
    temp_characteristics.set_size(decomposed.first);
    temp_characteristics.set_identifier(decomposed.second);
    file.set_characteristics(temp_characteristics);
    // file.get_characteristics().set_size(decomposed.first);
    // file.get_characteristics().set_identifier(decomposed.second);
    file.build_target_absolute();
}

void GroundWriter::write_single_ground(std::filesystem::path target, int value) const
{
    std::fstream ground;
    ground.open(target.string(), std::fstream::out | std::fstream::app);
    if (ground.is_open()) {
        ground << value;
        ground.close();
    }
}

std::pair<std::string, std::string> GroundWriter::decompose_filename(std::string filename) const
{
    std::vector<std::string> filename_parts;
    boost::split(filename_parts, filename, boost::is_any_of(FileIO::SPLIT_REGEX));

    assert(filename_parts.size() == 4);

    std::string size = filename_parts.at(2);
    std::string identifier = filename_parts.at(3).substr(1);

    return std::make_pair(size, identifier);
}
