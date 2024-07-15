#include <iostream>
#include <fstream>
#include "quantum_key_distribution.h"
#include "quantum_encryption.h"
#include "config_parser.h"
#include "logger.h"

void log_results(const std::string &message, const std::string &encrypted_message, const std::string &decrypted_message) {
    Logger::log("Original Message: " + message);
    Logger::log("Encrypted Message: " + encrypted_message);
    Logger::log("Decrypted Message: " + decrypted_message);
}

int main() {
    ConfigParser config("config/config.yaml");
    std::string key_length = config.get("quantum_key_length");

    // Initialize Quantum Key Distribution
    QuantumKeyDistribution qkd(std::stoi(key_length));
    std::string key = qkd.generate_key();
    Logger::log("Generated Quantum Key: " + key);

    // Encrypt and Decrypt a message using Quantum Encryption
    QuantumEncryption qe(key);
    std::string message = "Hello, Quantum World!";
    std::string encrypted_message = qe.encrypt(message);
    std::string decrypted_message = qe.decrypt(encrypted_message);

    log_results(message, encrypted_message, decrypted_message);

    // Write results to file
    std::ofstream result_file("results.txt");
    result_file << "Original Message: " << message << "\n";
    result_file << "Encrypted Message: " << encrypted_message << "\n";
    result_file << "Decrypted Message: " << decrypted_message << "\n";
    result_file.close();

    return 0;
}
