# Practical: Smart Pointers and RAII

## Aim
To learn how RAII ties resource lifetime to object lifetime and how `std::unique_ptr` and `std::shared_ptr` help prevent manual memory-management errors.

## Requirements
- C++11 or later (the example uses C++14-compatible smart-pointer features; compile with C++17).
- A C++ compiler such as g++.
- Optional: Valgrind on Linux, or AddressSanitizer where supported.

## Compile and run
```bash
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o smart_pointers
./smart_pointers
```

## Ownership comparison

| Type | Ownership | Resource release |
|---|---|---|
| Raw pointer | Does not express ownership by itself; the programmer must define who releases the resource | Manual `delete` / `delete[]` when dynamically allocated and owned |
| `std::unique_ptr` | One owner; it cannot be copied, but ownership can be moved | Automatically when the unique_ptr is destroyed or reset |
| `std::shared_ptr` | Multiple owners share a control block and ownership count | When the last shared_ptr owner is destroyed or reset |

Use `unique_ptr` by default when there is one owner. Use `shared_ptr` only when multiple parts genuinely need to keep the same resource alive. The Dashboard and Logger in this demo both retain the same Report, so shared ownership is appropriate. The program does not manually delete smart-pointer-managed resources.

## Memory checking

### Valgrind (Linux)
Compile with debug information, then run:
```bash
g++ -std=c++17 -g -O0 -Wall -Wextra main.cpp -o smart_pointers
valgrind --leak-check=full --show-leak-kinds=all ./smart_pointers
```

### AddressSanitizer (where supported)
```bash
g++ -std=c++17 -g -O1 -fsanitize=address -fno-omit-frame-pointer main.cpp -o smart_pointers_asan
./smart_pointers_asan
```

Record the actual tool output from your own computer in your submission. No Valgrind or AddressSanitizer run is claimed by this repository upload.

## Result / observation
RAII ties resource cleanup to object lifetime. A unique_ptr provides single ownership, while shared_ptr keeps a resource alive until its final owner is gone. Smart pointers remove the need for manual delete in these examples and help reduce leaks caused by forgotten cleanup.

## Benchmark note
This practical demonstrates ownership and lifetime; it is not a performance benchmark. Runtime and memory measurements depend on compiler, build options, operating system, hardware, and workload. If measurements are required, record those conditions and the tool used.
