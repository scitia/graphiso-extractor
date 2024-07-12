#include "graphio.hpp"

void GraphIO::generate_name(const std::string old_filename) const
{
    
}

void GraphIO::convert() const
{
    std::string source_path = this->reader.read_property(FileIO::CONFIG_DB_SOURCE);
    std::string target_path = this->reader.read_property(FileIO::CONFIG_DB_TARGET);

    for (const auto& entry : std::filesystem::recursive_directory_iterator(source_path)) {
        if (std::filesystem::is_regular_file(entry.path())) {

            // procedure of unpacking nad saving file should be executed here
            std::cout << std::string(20, '_') << std::endl;
            // old absolute
            std::string source_absolute = std::filesystem::absolute(entry.path()).string();
            std::cout << source_absolute << std::endl;
            // old and new relative are common
            std::string relative_path = this->reader.relative_path(entry.path().parent_path().string(), source_path);
            std::cout << relative_path << std::endl; // relative path
            // filename
            std::string filename = entry.path().filename().string();
            std::cout << filename << std::endl;
            // new absolute
            std::string target_absolute = target_path + "\\" + relative_path + "\\" + filename;
            std::cout << target_absolute << std::endl; 

            std::cout << std::string(20, '_') << std::endl;
        }
    }
}
