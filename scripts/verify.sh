#!/bin/bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

"${ROOT_DIR}/scripts/run_simulation.sh"
"${ROOT_DIR}/scripts/smoke_test.sh"

echo "All verification checks passed."
