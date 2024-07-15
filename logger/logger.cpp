#include "logger.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <iomanip>

void Logger::log(const std::string &message) {
    std::ofstream log_file("log.txt", std::ios_base::app);
    if (log_file.is_open()) {
        std::time_t now = std::time(nullptr);
        log_file << "[" << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S") << "] " << message << std::endl;
    } else {
        std::cerr << "Unable to open log file." << std::endl;
    }
}
