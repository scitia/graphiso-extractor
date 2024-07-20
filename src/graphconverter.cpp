#include "graphconverter.hpp"

GraphConverter::GraphConverter()
{
   this->source_db_uri = std::filesystem::path(this->config.read_property(FileIO::CONFIG_DB_SOURCE));
   this->target_db_uri = std::filesystem::path(this->config.read_property(FileIO::CONFIG_DB_TARGET));
   this->ground_db_uri = std::filesystem::path(this->config.read_property(FileIO::CONFIG_DB_GROUND));
}

void GraphConverter::preactions() const
{
    create_required_directories(this->target_db_uri);
    BOOST_LOG_TRIVIAL(info) << "Required directories structure was created";
}

void GraphConverter::postactions()
{
    reader.set_context(std::make_unique<GroundReader>());
    writer.set_context(std::make_unique<GroundWriter>());

    GFile ground;

    for (const auto& entry : std::filesystem::recursive_directory_iterator(this->ground_db_uri)) {
        if (std::filesystem::is_regular_file(entry.path())) {
            ground = GroundFile(entry.path());
            try {
                this->reader.read(ground);
            } catch (std::exception ex) {
                BOOST_LOG_TRIVIAL(error) << "An error occured during reading ground-truth file";
                BOOST_LOG_TRIVIAL(error) << ex.what();
            }

            try {
                this->writer.write(ground);
            } catch (std::exception ex) {
                BOOST_LOG_TRIVIAL(error) << "An error occured during writing ground-truth file";
                BOOST_LOG_TRIVIAL(error) << ex.what();
            }
        }
    }

    BOOST_LOG_TRIVIAL(info) << "Ground truth files was processed";
}

void GraphConverter::convert()
{
    reader.set_context(std::make_unique<GraphReader>());
    writer.set_context(std::make_unique<GraphWriter>());

    GFile graph;

    for (const auto& entry : std::filesystem::recursive_directory_iterator(this->ground_db_uri)) {
        if (std::filesystem::is_regular_file(entry.path())) {
            graph = GroundFile(entry.path());
            try {
                this->reader.read(graph);
            } catch (std::exception ex) {
                BOOST_LOG_TRIVIAL(error) << "An error occured during reading graph file";
                BOOST_LOG_TRIVIAL(error) << ex.what();
            }

            try {
                this->writer.write(graph);
            } catch (std::exception ex) {
                BOOST_LOG_TRIVIAL(error) << "An error occured during writing graph file";
                BOOST_LOG_TRIVIAL(error) << ex.what();
            }
        }
    }

    BOOST_LOG_TRIVIAL(info) << "Database was processed";
}

void GraphConverter::base_procedure(std::filesystem::path path, std::function<void(std::filesystem::path path)> procedure)
{
    for (const auto& entry : std::filesystem::recursive_directory_iterator(path)) {
        if (std::filesystem::is_regular_file(entry.path())) {
            procedure(entry.path());
        }
    }
}

void GraphConverter::create_required_directories(std::filesystem::path path) const
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

	std::map<std::string, std::map<std::string, std::vector<std::string>>> directory_map {
		{"iso", group_map},
		{"si2", group_map},
		{"si4", group_map},
		{"si6", group_map}
	};

	for (auto const& [ekey, evalue] : directory_map) {

		std::string parent = ekey;
		for (auto const& [ikey, ivalue] : evalue) {
			std::string child = ikey;
			for (auto const& leaf : ivalue) {
				std::vector<std::string> parts{ parent, child, leaf };
				std::string rel_path = boost::algorithm::join(parts, FileIO::UNIX_SEPARATOR);
				this->fs_utils.create_directory(path, rel_path);
			}
		}
	}
}
