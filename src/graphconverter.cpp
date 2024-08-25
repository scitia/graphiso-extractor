#include "graphconverter.hpp"

const int GraphConverter::GRAPHS_VOLUME = 145600;
const int GraphConverter::DIR_VOLUME = 84;

GraphConverter::GraphConverter()
{
   this->resource.set_source(std::filesystem::path(this->config.read_property(FileIO::CONFIG_DB_SOURCE)));
   this->resource.set_target(std::filesystem::path(this->config.read_property(FileIO::CONFIG_DB_TARGET)));
   this->resource.set_ground(std::filesystem::path(this->config.read_property(FileIO::CONFIG_DB_GROUND)));
}

void GraphConverter::initially() const
{
    std::cout << std::endl << "GraphISO-Extractor by Kacper Liżewski©" << std::endl;
    std::cout << FileIO::APP_TITLE << std::endl;
    BOOST_LOG_TRIVIAL(info) << "Starting the conversion process";
}

void GraphConverter::finally() const
{
    BOOST_LOG_TRIVIAL(info) << "Conversion process completed";
}

void GraphConverter::healthcheck() const
{
    //TODO report of data completeness
    BOOST_LOG_TRIVIAL(info) << "Healthcheck was generated";
}

void GraphConverter::preactions() const
{
    create_required_directories(this->resource.get_target());
    BOOST_LOG_TRIVIAL(info) << "Required directories structure was created";
}

void GraphConverter::postactions()
{
    reader.set_context(std::make_unique<GroundReader>());
    writer.set_context(std::make_unique<GroundWriter>());

    progressbar progress(DIR_VOLUME);
    GlobalUtils::spc(progress);

    GroundFile* ground;

    for (const auto& entry : std::filesystem::recursive_directory_iterator(this->resource.get_ground())) {
        if (std::filesystem::is_regular_file(entry.path())) {
            ground = new GroundFile(entry.path(), this->resource);
            try {
                ground = dynamic_cast<GroundFile*>(this->reader.read(*ground));
            } catch (std::exception ex) {
                BOOST_LOG_TRIVIAL(error) << "An error occured during reading ground-truth file";
                BOOST_LOG_TRIVIAL(error) << ex.what();
            }

            try {
                this->writer.write(*ground);
            } catch (std::exception ex) {
                BOOST_LOG_TRIVIAL(error) << "An error occured during writing ground-truth file";
                BOOST_LOG_TRIVIAL(error) << ex.what();
            }

            progress.update();
        }
    }
    BOOST_LOG_TRIVIAL(info) << std::endl << "Ground truth files were processed";
}

void GraphConverter::convert()
{
    reader.set_context(std::make_unique<GraphReader>());
    writer.set_context(std::make_unique<GraphWriter>());

    progressbar progress(GRAPHS_VOLUME);
    GlobalUtils::spc(progress);

    GraphFile* graph;

    for (const auto& entry : std::filesystem::recursive_directory_iterator(this->resource.get_source())) {
        if (std::filesystem::is_regular_file(entry.path())) {
            graph = new GraphFile(entry.path(), this->resource);
            try {
                graph = dynamic_cast<GraphFile*>(reader.read(*graph));
            } catch (std::exception ex) {
                BOOST_LOG_TRIVIAL(error) << "An error occured during reading graph file";
                BOOST_LOG_TRIVIAL(error) << ex.what();
            }

            try {
                writer.write(*graph);
            } catch (std::exception ex) {
                BOOST_LOG_TRIVIAL(error) << "An error occured during writing graph file";
                BOOST_LOG_TRIVIAL(error) << ex.what();
            }

            progress.update();
        }
    }
    BOOST_LOG_TRIVIAL(info) << std::endl << "Database was processed";
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
                FilesystemUtils::create_directory(path, rel_path);
			}
		}
	}
}