#include "filewriter.hpp"

void FileWriter::create_directory(const std::string &parent_path, const std::string &directory_name) const
{
        std::filesystem::path target_path(
        parent_path
        + FileIO::UNIX_SEPARATOR
        + directory_name
    );

    if (std::filesystem::exists(target_path) && std::filesystem::is_directory(target_path)) {
        return;
    }

    std::filesystem::create_directories(target_path);
}

void FileWriter::create_required_directories(const std::string &target_path) const
{
    std::vector<std::string> bvg_vec {
		"b03", "b03m", "b06", "b06m", "b09", "b09m"
	};
	std::vector<std::string> m2D_vec {
		"m2D", "m2Dr2", "m2Dr4", "m2Dr6"
	};
	std::vector<std::string> m3D_vec {
		"m3D", "m3Dr2", "m3Dr4", "m3Dr6"
	};
	std::vector<std::string> m4D_vec {
		"m4D", "m4Dr2", "m4Dr4", "m4Dr6"
	};
	std::vector<std::string> rnd_vec {
		"r001", "r005", "r01"
	};

	std::map<std::string, std::vector<std::string>> group_map {
		{"bvg", bvg_vec},
		{"m2D", m2D_vec},
		{"m3D", m3D_vec},
		{"m4D", m4D_vec},
		{"rand", rnd_vec}
	};

	std::map<std::string, std::map<std::string, std::vector<std::string>>> calalogue_map {
		{"iso", group_map},
		{"si2", group_map},
		{"si4", group_map},
		{"si6", group_map}
	};

	std::vector<std::string> test_paths;

	for (auto const& [ekey, evalue] : calalogue_map) {

		std::string parent = ekey;
		for (auto const& [ikey, ivalue] : evalue) {

			std::string child = ikey;
			for (auto const& leaf : ivalue) {
				std::vector<std::string> parts{ parent, child, leaf };
				std::string rel_path = boost::algorithm::join(parts, FileIO::UNIX_SEPARATOR);
				create_directory(target_path, rel_path);
			}
		}
	}
}
