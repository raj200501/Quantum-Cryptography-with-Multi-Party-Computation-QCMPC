#ifndef YAML_CPP_YAML_H
#define YAML_CPP_YAML_H

#include <fstream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

namespace YAML {

class Exception : public std::runtime_error {
public:
    explicit Exception(const std::string &message) : std::runtime_error(message) {}
};

class Node {
public:
    Node() = default;

    bool Has(const std::string &key) const {
        return values.find(key) != values.end();
    }

    Node operator[](const std::string &key) const {
        Node child;
        auto it = values.find(key);
        if (it != values.end()) {
            child.scalar = it->second;
            child.is_scalar = true;
        }
        return child;
    }

    template <typename T>
    T as() const {
        std::istringstream stream(scalar);
        T value{};
        if (!(stream >> value)) {
            throw Exception("Unable to parse scalar value");
        }
        return value;
    }

    void Set(const std::string &key, const std::string &value) {
        values[key] = value;
    }

private:
    std::map<std::string, std::string> values;
    std::string scalar;
    bool is_scalar{false};
};

template <>
inline std::string Node::as<std::string>() const {
    if (!is_scalar) {
        throw Exception("Unable to parse scalar string value");
    }
    return scalar;
}

inline std::string Trim(const std::string &value) {
    size_t start = value.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) {
        return "";
    }
    size_t end = value.find_last_not_of(" \t\r\n");
    return value.substr(start, end - start + 1);
}

inline Node LoadFile(const std::string &file_path) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        throw Exception("Unable to open file: " + file_path);
    }

    Node node;
    std::string line;
    while (std::getline(file, line)) {
        std::string trimmed = Trim(line);
        if (trimmed.empty() || trimmed.rfind("#", 0) == 0) {
            continue;
        }
        auto delimiter = trimmed.find(':');
        if (delimiter == std::string::npos) {
            continue;
        }
        std::string key = Trim(trimmed.substr(0, delimiter));
        std::string value = Trim(trimmed.substr(delimiter + 1));
        if (!key.empty()) {
            node.Set(key, value);
        }
    }
    return node;
}

} // namespace YAML

#endif // YAML_CPP_YAML_H
