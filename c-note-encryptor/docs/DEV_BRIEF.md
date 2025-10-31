# Development Brief

This repository contains the scaffold for the Password-Protected Note Encryption Tool.
The goal of this brief is to document the agreed-upon structure and constraints so
future implementation steps stay aligned with the project requirements.

## Functional Overview
- Command-line utility written in C.
- Supports encrypt (`-e`) and decrypt (`-d`) actions.
- Uses XOR with the **first character of the password** for transformations (to be
  implemented in a later step).
- Reads plain-text files and produces encrypted output, or vice versa.

## Architectural Guidelines
- `main.c` handles CLI parsing, basic validation, and delegates to the
  transformation layer.
- `encrypt.c` will host the encryption/decryption implementations.
- `loglist.c` demonstrates the required self-referential structure by maintaining
  a simple linked list of log entries.
- Shared data structures live in `include/types.h`.
- Public APIs are declared in `include/encrypt.h` and `include/loglist.h`.

## Data Structures
- `enum EncryptionMode` differentiates encrypt vs decrypt operations.
- `struct NoteInfo` stores input/output file paths and the selected mode.
- `struct Flags` contains bit-field status flags used by the CLI layer.
- `struct LogNode` (defined in `loglist.h`) is a singly linked list node.

## Coding Constraints
- Follow C11 with `-Wall -Wextra -pedantic` warnings enabled.
- Demonstrate usage of `fscanf`/`fprintf` in the final implementation while
  keeping the main file I/O loop byte-oriented for fidelity.
- Keep `main.c` minimal; heavy logic belongs in helper modules.
- Provide clear exit codes and human-readable error messages.

## Deliverables for Scaffold Step
- Source and header files exist with header guards and stub implementations.
- `README.md` documents the project purpose, build command, and structure.
- `docs/pseudocode.md` and `docs/flowchart.txt` outline the planned control flow.
- Build succeeds even though business logic is not yet implemented.

Subsequent tasks will fill in functional behavior, tests, and documentation.
