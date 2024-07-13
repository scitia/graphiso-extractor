#include "graphfile.hpp"

GraphFile::GraphFile(std::filesystem::path &path) : GraphFileBase(path)
{
    std::vector<std::string> filename_parts;
    boost::split(filename_parts, this->get_filename(), boost::is_any_of("_."));

    this->congruence = filename_parts.at(0);
    this->group = filename_parts.at(1);
    this->size_group = filename_parts.at(2);
    this->ordinal = filename_parts.at(3);

    this->set_target_filename(boost::algorithm::join(filename_parts, FileIO::UNDERSCORE).append(FileIO::CSV_EXTENSION));
    this->set_target_absolute(this->build_target_absolute());
}

const std::string GraphFile::build_target_absolute() const
{
    std::string target_uri = this->get_reader().read_property(FileIO::CONFIG_DB_TARGET);
    return target_uri
        .append(this->get_relative())
        .append(this->get_target_filename());
}
