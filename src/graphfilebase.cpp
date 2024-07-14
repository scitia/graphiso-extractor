#include "graphfilebase.hpp"

GraphFileBase::GraphFileBase(std::filesystem::path &path, const std::string source_db_uri, std::string target_db_uri)
{
    this->source_db_uri = source_db_uri;
    this->target_db_uri = target_db_uri;
    this->filename = path.filename().string();
    this->relative = this->reader.relative_path(path.parent_path().string(), this->source_db_uri);
    this->source_absolute = std::filesystem::absolute(path).string();
}

void GraphFileBase::to_string() const
{
    std::cout << std::string(60, '_') << std::endl;
    std::cout << "Filename: " << this->filename << std::endl;
    std::cout << "Relative: " << this->relative << std::endl;
    std::cout << "New filename: " << this->target_filename << std::endl;
    std::cout << "Source absolute path: " << this->source_absolute << std::endl;
    std::cout << "Target absolute path: " << this->target_absolute << std::endl;
    std::cout << std::string(60, '_') << std::endl;
}

//getters

const std::string GraphFileBase::get_filename() const
{
    return this->filename;
}

const std::string GraphFileBase::get_relative() const
{
    return this->relative;
}

const std::string GraphFileBase::get_source_absolute() const
{
    return this->source_absolute;
}

const std::string GraphFileBase::get_target_absolute() const
{
    return this->target_absolute;
}

const std::string GraphFileBase::get_target_filename() const
{
    return this->target_filename;
}

const std::string GraphFileBase::get_source_db_uri() const
{
    return this->source_db_uri;
}

const std::string GraphFileBase::get_target_db_uri() const
{
    return this->target_db_uri;
}

const FileReader GraphFileBase::get_reader() const
{
    return this->reader;
}

void GraphFileBase::set_target_absolute(std::string target_absolute)
{
    this->target_absolute = std::move(target_absolute);
}

void GraphFileBase::set_target_filename(std::string target_filename)
{
    this->target_filename = std::move(target_filename);
}
