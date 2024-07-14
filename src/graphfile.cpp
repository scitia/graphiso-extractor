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
    set_pair_characteristics();

    this->set_target_filename(boost::algorithm::join(filename_parts, FileIO::UNDERSCORE).append(FileIO::CSV_EXTENSION));
    this->set_target_absolute(this->build_target_absolute());
}

const std::string GraphFile::build_target_absolute() const
{
    std::string base_uri = this->get_target_db_uri();

    std::string target_path = base_uri
        .append(this->get_relative())
        .append(FileIO::UNIX_SEPARATOR)
        .append(this->get_size_group())
        .append(FileIO::UNIX_SEPARATOR)
        .append(this->get_pair_id());

    this->get_writer().create_directories(target_path);

    return target_path
        .append(FileIO::UNIX_SEPARATOR)
        .append(this->get_target_filename());
}

// getters

const std::string GraphFile::get_congruence() const
{
    return this->congruence;
}

const std::string GraphFile::get_group() const
{
    return this->group;
}

const std::string GraphFile::get_size_group() const
{
    return this->size_group;
}

const std::string GraphFile::get_ordinal() const
{
    return this->ordinal;
}

const std::string GraphFile::get_pair_label() const
{
    return this->pair_label;
}

const std::string GraphFile::get_pair_id() const
{
    return this->pair_id;
}

// private methods

void GraphFile::set_pair_characteristics()
{
    assert(this->ordinal.length() == 3);
    this->pair_label = this->ordinal.substr(0,1);
    this->pair_id = this->ordinal.substr(1);
}
