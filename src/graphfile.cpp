#include "graphfile.hpp"

GraphFile::GraphFile(std::filesystem::path &path, const std::string source_db_uri, const std::string target_db_uri) 
: GraphFileBase(path, source_db_uri, target_db_uri)
{
    std::vector<std::string> filename_parts;
    boost::split(filename_parts, this->get_filename(), boost::is_any_of(FileIO::SPLIT_REGEX));

    this->congruence = filename_parts.at(0);
    this->group = filename_parts.at(1);
    this->size_group = filename_parts.at(2);
    this->ordinal = filename_parts.at(3);

    this->set_target_filename(boost::algorithm::join(filename_parts, FileIO::UNDERSCORE).append(FileIO::CSV_EXTENSION));
    this->set_target_absolute(this->build_target_absolute());
}

const std::string GraphFile::build_target_absolute() const
{
    std::string target_uri = this->get_target_db_uri();
    return target_uri
        .append(this->get_relative())
        .append(FileIO::UNIX_SEPARATOR)
        .append(this->get_target_filename());
}
