#ifndef CONFIG_PARSER_H
#define CONFIG_PARSER_H

#include <string>
#include <yaml-cpp/yaml.h>

class ConfigParser {
public:
    ConfigParser(const std::string &file_path);
    std::string get(const std::string &key);

private:
    YAML::Node config;
};

#endif // CONFIG_PARSER_H
