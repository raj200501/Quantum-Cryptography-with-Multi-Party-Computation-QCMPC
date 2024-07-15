#include "config_parser.h"
#include <fstream>
#include <iostream>
#include <yaml-cpp/yaml.h>

ConfigParser::ConfigParser(const std::string &file_path) {
    try {
        config = YAML::LoadFile(file_path);
    } catch (const YAML::Exception &e) {
        std::cerr << "Error loading config file: " << e.what() << std::endl;
        throw;
    }
}

std::string ConfigParser::get(const std::string &key) {
    try {
        return config[key].as<std::string>();
    } catch (const YAML::Exception &e) {
        std::cerr << "Error getting key: " << key << " - " << e.what() << std::endl;
        throw;
    }
}
