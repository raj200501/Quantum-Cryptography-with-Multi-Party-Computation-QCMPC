#!/bin/bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

"${ROOT_DIR}/scripts/run_simulation.sh" > "${ROOT_DIR}/smoke_test.log" 2>&1

RESULTS_PATH=""
if [ -f "${ROOT_DIR}/results.txt" ]; then
    RESULTS_PATH="${ROOT_DIR}/results.txt"
elif [ -f "${ROOT_DIR}/quantum_cryptography/results.txt" ]; then
    RESULTS_PATH="${ROOT_DIR}/quantum_cryptography/results.txt"
else
    echo "results.txt not found after simulation." >&2
    exit 1
fi

grep -q "Original Message" "${RESULTS_PATH}"

echo "Smoke test passed."
