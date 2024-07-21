#include "gfile.hpp"

GFile::GFile(const sfs::path filepath)
{
    this->path = filepath;
    this->characteristics = GraphCharacteristics(filepath);
}

const sfs::path GFile::relative_toward(const sfs::path base_path) const
{
    return sfs::relative(this->path.parent_path(), base_path);
}

const sfs::path GFile::absolute() const
{
    return sfs::absolute(this->path);
}

const sfs::path GFile::get_path() const
{
    return this->path;
}

const sfs::path GFile::get_target_path() const
{
    return this->target_path;
}

void GFile::set_target_path(std::filesystem::path target_path)
{
    this->target_path = std::move(target_path);
}

const GraphCharacteristics GFile::get_characteristics() const
{
    return this->characteristics;
}
