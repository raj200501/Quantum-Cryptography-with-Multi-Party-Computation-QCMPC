#include "quantum_encryption.h"
#include <bitset>
#include <iostream>
#include <sstream>
#include <iomanip>

QuantumEncryption::QuantumEncryption(const std::string &key) : key(key) {}

std::string QuantumEncryption::encrypt(const std::string &message) {
    std::string encrypted_message;
    for (size_t i = 0; i < message.size(); ++i) {
        encrypted_message += message[i] ^ key[i % key.size()];
    }
    std::cout << "Encrypting message: " << message << " to " << to_hex(encrypted_message) << std::endl;
    return encrypted_message;
}

std::string QuantumEncryption::decrypt(const std::string &encrypted_message) {
    std::cout << "Decrypting message: " << to_hex(encrypted_message) << std::endl;
    return encrypt(encrypted_message); // Symmetric encryption
}

std::string QuantumEncryption::to_hex(const std::string &str) {
    std::stringstream ss;
    for (const auto &ch : str) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)ch;
    }
    return ss.str();
}
