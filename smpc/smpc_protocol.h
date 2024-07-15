#ifndef SMPC_PROTOCOL_H
#define SMPC_PROTOCOL_H

#include <vector>

class SMPCProtocol {
public:
    SMPCProtocol(int num_parties);
    std::vector<int> secure_addition(const std::vector<std::vector<int>> &inputs);
    std::vector<int> secure_multiplication(const std::vector<std::vector<int>> &inputs);
    void distribute_shares(const std::vector<int> &secret, std::vector<std::vector<int>> &shares);
    std::vector<int> reconstruct_secret(const std::vector<std::vector<int>> &shares);

private:
    int num_parties;
};

#endif // SMPC_PROTOCOL_H
