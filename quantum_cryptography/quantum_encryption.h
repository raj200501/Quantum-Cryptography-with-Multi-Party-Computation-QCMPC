#ifndef QUANTUM_ENCRYPTION_H
#define QUANTUM_ENCRYPTION_H

#include <string>

class QuantumEncryption {
public:
    QuantumEncryption(const std::string &key);
    std::string encrypt(const std::string &message);
    std::string decrypt(const std::string &encrypted_message);

private:
    std::string key;
    std::string to_hex(const std::string &str);
};

#endif // QUANTUM_ENCRYPTION_H
