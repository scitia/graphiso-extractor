#include "graphio.hpp"

void GraphIO::convert() const
{
    std::string source_path = this->reader.read_property(FileIO::CONFIG_DB_SOURCE);

    for (const auto& entry : std::filesystem::recursive_directory_iterator(source_path)) {
        if (std::filesystem::is_regular_file(entry.path())) {

            std::filesystem::path path = entry.path();
            GraphFile gf(path);

            // rest of procedure
        }
    }
}
