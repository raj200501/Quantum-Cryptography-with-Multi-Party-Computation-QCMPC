#ifndef QUANTUM_KEY_DISTRIBUTION_H
#define QUANTUM_KEY_DISTRIBUTION_H

#include <string>

class QuantumKeyDistribution {
public:
    QuantumKeyDistribution(int key_length);
    std::string generate_key();
    void error_correction();
    void privacy_amplification();

private:
    int key_length;
};

#endif // QUANTUM_KEY_DISTRIBUTION_H
