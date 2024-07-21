#include "filesystemutils.hpp"

bool FilesystemUtils::create_directory(std::filesystem::path path, std::string directory_name)
{
    std::filesystem::path target_path(path.string().append(FileIO::UNIX_SEPARATOR).append(directory_name));
    if (std::filesystem::exists(target_path) && std::filesystem::is_directory(target_path)) {
        return false;
    }
    return std::filesystem::create_directories(target_path);
}

bool FilesystemUtils::create_directories(std::filesystem::path path)
{
    if (std::filesystem::exists(path) && std::filesystem::is_directory(path)) {
		return false;
	}
    return std::filesystem::create_directories(path);
}