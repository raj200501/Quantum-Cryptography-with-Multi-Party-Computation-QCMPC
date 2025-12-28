#!/bin/bash

# Run the quantum cryptography and SMPC simulation

set -e

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

echo "=================================================="
echo " Quantum Cryptography with Multi-Party Computation "
echo "=================================================="

build_quantum() {
    cd "${ROOT_DIR}/quantum_cryptography"
    echo "Building quantum cryptography simulation..."
    g++ -std=c++17 -I"${ROOT_DIR}" -I"${ROOT_DIR}/config" -I"${ROOT_DIR}/logger" \
        main.cpp quantum_key_distribution.cpp quantum_encryption.cpp \
        "${ROOT_DIR}/config/config_parser.cpp" "${ROOT_DIR}/logger/logger.cpp" \
        -o main
}

build_smpc() {
    cd "${ROOT_DIR}/smpc"
    echo "Building SMPC simulation..."
    g++ -std=c++17 secure_computation.cpp smpc_protocol.cpp main.cpp -o secure_computation
}

build_quantum
build_smpc

cd "${ROOT_DIR}"

echo "Running quantum cryptography simulation..."
"${ROOT_DIR}/quantum_cryptography/main"

echo "Running SMPC simulation..."
"${ROOT_DIR}/smpc/secure_computation"

if [ -f "${ROOT_DIR}/results.txt" ]; then
    echo "Quantum results saved to ${ROOT_DIR}/results.txt"
fi
if [ -f "${ROOT_DIR}/smpc_results.txt" ]; then
    echo "SMPC results saved to ${ROOT_DIR}/smpc_results.txt"
fi

exit 0

cd quantum_cryptography
./main

cd ../smpc
./secure_computation
