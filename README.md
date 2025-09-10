# Anti-Debugging Validation Suite for the Witchcraft Compiler Collection

This repository provides empirical validation of WSH's resilience against common anti-debugging techniques, supporting claims made in Section 2.8.6 of "Beyond Reachability: Cross-Architecture Binary Libification and Procedural Debugging for Vulnerability Assessment."

## Overview

Traditional debugging tools face systematic limitations when analyzing binaries employing anti-debugging protections. This test suite validates that WSH's procedural debugging approach bypasses these limitations through four representative test cases.

## Test Cases

### 1. Anti-ptrace Protection (`anti-ptrace.c`)
- **Technique**: Uses `ptrace(PTRACE_TRACEME)` to detect debugger attachment
- **Traditional impact**: gdb and strace fail with "don't trace me!!" message
- **WSH approach**: Bypasses detection via `dlopen()` loading mechanism
- **Expected output**: `PASS`

### 2. Breakpoint Detection (`breakpoint_detection.c`)
- **Technique**: Scans memory for INT3 (0xcc) breakpoint instructions
- **Traditional impact**: gdb breakpoint placement triggers detection
- **WSH approach**: Direct function calls without breakpoint insertion
- **Expected output**: `No breakpoint detected...` followed by `PASS`

### 3. Control Flow Manipulation (`pc_manipulation.c`)
- **Technique**: Employs return address manipulation to alter execution flow
- **Traditional impact**: Variable depending on debugging strategy
- **WSH approach**: Metadata-based loading unaffected by runtime modifications
- **Expected output**: `42` followed by `PASS`

### 4. Packed Binary Analysis (`upx-test.wsh`)
- **Technique**: UPX-compressed libcrypto.so (5.3MB → 2.7MB, 50.7% reduction)
- **Traditional impact**: Static analysis tools require manual unpacking
- **WSH approach**: Leverages runtime unpacking via `dlopen()`
- **Expected output**: `PASS` (confirms MD5 computation through packed library)

## Requirements

- Ubuntu 20.04+ (tested on Ubuntu 24.04 LTS)
- Witchcraft Compiler Collection v0.0.11+ installed and in PATH
- Standard development tools: gcc, make
- UPX packer (for packed binary test)

## Installation and Execution

### Clone repository
git clone https://github.com/endrazine/wcc-anti-debug.git
cd wcc-anti-debug

### Build test binaries
make

### Run all validation tests
make test

## Expected Output
When all tests pass, you should see:
./test.wsh ./anti-ptrace
 ** libifying ./anti-ptrace to //tmp/.wsh-XXXXX/anti-ptrace (18584 bytes)
 ** loading of libified binary succeeded
PASS

./test.wsh ./breakpoint_detection
 ** libifying ./breakpoint_detection to //tmp/.wsh-XXXXX/breakpoint_detection (17368 bytes)
 ** loading of libified binary succeeded
No breakpoint detected...
PASS

./test.wsh ./pc_manipulation
 ** libifying ./pc_manipulation to //tmp/.wsh-XXXXX/pc_manipulation (17520 bytes)
 ** loading of libified binary succeeded
42
PASS

./upx-test.wsh
PASS

