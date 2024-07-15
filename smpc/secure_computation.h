#ifndef SECURE_COMPUTATION_H
#define SECURE_COMPUTATION_H

#include "smpc_protocol.h"

class SecureComputation {
public:
    SecureComputation(int num_parties);
    ~SecureComputation();
    void execute_protocols();

private:
    int num_parties;
    SMPCProtocol *smpc_protocol;
};

#endif // SECURE_COMPUTATION_H
