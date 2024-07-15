#include "secure_computation.h"
#include "smpc_protocol.h"
#include <iostream>

SecureComputation::SecureComputation(int num_parties) : num_parties(num_parties) {
    smpc_protocol = new SMPCProtocol(num_parties);
}

SecureComputation::~SecureComputation() {
    delete smpc_protocol;
}

void SecureComputation::execute_protocols() {
    std::vector<int> secret = {42, 56, 78};
    std::vector<std::vector<int>> shares(num_parties, std::vector<int>(secret.size()));

    smpc_protocol->distribute_shares(secret, shares);

    std::vector<int> reconstructed_secret = smpc_protocol->reconstruct_secret(shares);
    std::cout << "Reconstructed Secret: ";
    for (const int &val : reconstructed_secret) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::vector<std::vector<int>> inputs = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::vector<int> sum = smpc_protocol->secure_addition(inputs);
    std::vector<int> product = smpc_protocol->secure_multiplication(inputs);

    std::cout << "Secure Addition Result: ";
    for (const int &val : sum) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "Secure Multiplication Result: ";
    for (const int &val : product) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}
