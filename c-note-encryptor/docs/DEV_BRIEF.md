# Development Brief (Scaffold Stage)

This brief tracks the scaffold expectations and the latest update from Prompt C.

- Headers include guards and shared types for modes, flags, and status codes.
- Source files now contain real byte-wise XOR logic keyed by the first password character.
- Makefile builds all sources into the `c-note-encryptor` binary.
- Documentation (pseudocode, flowchart) reflects the current CLI, password handling, and
  XOR transform steps.
- Repository structure matches the agreed layout so future prompts can focus on polish,
  testing, and usability improvements.
This brief captures the expectations that guided the initial scaffold created via Prompt A.

- Provide headers with include guards and forward declarations only.
- Implement source files with no real business logic yet; use simple stubs that compile.
- Generate a Makefile capable of building all sources into the `c-note-encryptor` binary.
- Supply lightweight documentation references (pseudocode and flowchart placeholders).
- Ensure the repository structure matches the agreed project layout so subsequent prompts can
  build on a stable foundation.
- Parse CLI flags (-e/-d) and prompt for a non-empty password while routing into stubbed
  encrypt/decrypt functions so later work can focus on real I/O logic.
# C Mini-Project: Password-Protected Note Encryptor


## 1. 🎯 Core Project Objective & Constraints

* **Goal:** Build a modular, command-line tool in C to encrypt and decrypt text files using a symmetric key.
* **Encryption Algorithm:** Simple XOR operation.
* **XOR Key Rule (MANDATORY):** The key for the XOR operation **must** be the **first character of the password** (`password[0]`). [cite_start]Mention this limitation in the README. [cite: 33, 34]
* [cite_start]**File Handling:** Input and output are text files (ASCII/UTF-8). [cite: 31]
* **Password Input:** The program must prompt the user for the password via the terminal. [cite_start]Visible echo is acceptable. [cite: 35]

## 2. 🎛️ Command-Line Interface (CLI) Contract

The executable must be named `tool` and accept exactly three arguments:

* **Executable Name:** `tool` (e.g., `./tool`)
* [cite_start]**Encryption Usage:** `./tool -e <input_file.txt> <output_file.enc>` [cite: 8]
* [cite_start]**Decryption Usage:** `./tool -d <input_file.enc> <output_file.txt>` [cite: 9]

## 3. 🧩 Mandatory C Concepts (Non-Negotiable)

[cite_start]The generated code must use the following concepts as specified: [cite: 36, 159, 160]

| Concept | Application in Project | File Location |
| :--- | :--- | :--- |
| `struct` and `enum` | Define `EncryptionMode` enum and `NoteInfo` struct. | [cite_start]`include/types.h` [cite: 163] |
| **Bit-fields** | Define `struct Flags` for compact status flags. | [cite_start]`include/types.h` [cite: 176] |
| **Self-referential structure** | Define `struct LogNode` for a simple linked list log system. | [cite_start]`src/loglist.c` / `include/loglist.h` [cite: 164] |
| `fscanf()`, `fprintf()` | Must be demonstrated for reading/writing file content or metadata. | [cite_start]`src/encrypt.c` [cite: 162] |
| **Modular Design** | Code must be split across the files listed below. | [cite_start]`src/` and `include/` [cite: 167, 168] |
| `main.c` Role | Must be minimal: only argument parsing, prompting, and calling high-level functions. | [cite_start]`src/main.c` [cite: 169, 170] |

## 4. 📂 Required Architecture & Data Structures

### Modules & Responsibilities

| File | Primary Responsibility | Notes |
| :--- | :--- | :--- |
| `src/main.c` | Parse CLI args, prompt password, call `encrypt_file()`/`decrypt_file()`. | [cite_start]Minimal logic here. [cite: 44] |
| `src/encrypt.c` | Implement XOR encryption/decryption logic and handle file I/O operations. | [cite_start]Contains `encrypt_file()` and `decrypt_file()`. [cite: 47] |
| `src/loglist.c` | Implement linked list functions (`append`, `print`, `free`). | [cite_start]Demonstrates self-referential struct. [cite: 54, 55] |
| `include/types.h` | Global type definitions. | [cite_start]Central for all mandatory structs/enums. [cite: 52] |
| `Makefile` | Multi-file compilation and build automation. [cite_start]| [cite: 59, 60] |

### Key Data Types

**All signatures must be used exactly as defined:**

* [cite_start]**Enum:** `enum EncryptionMode { MODE_ENCRYPT, MODE_DECRYPT };` [cite: 77]
* **Info Struct:** `struct NoteInfo { const char* in_path; const char* out_path; enum EncryptionMode mode; [cite_start]};` [cite: 77, 78]
* **Bit-fields:** `struct Flags { unsigned has_password:1; unsigned io_ok:1; unsigned mode_set:1; unsigned reserved:5; [cite_start]};` [cite: 79]
* **Self-referential Struct:** `struct LogNode { char entry[128]; struct LogNode* next; [cite_start]};` [cite: 80]

## 5. 🛑 Error Handling & Acceptance Criteria

### Exit Codes

* [cite_start]**`0`**: Success. [cite: 222]
* [cite_start]**`2`**: Bad command-line arguments (print usage message). [cite: 223]
* [cite_start]**`3`**: File I/O error (e.g., cannot open/write file). [cite: 223]
* [cite_start]**`4`**: Password error (e.g., empty password). [cite: 223]

### Edge Case Policy

* [cite_start]**Same Input/Output Path:** The program **must refuse** this operation with an error. [cite: 263]
* [cite_start]**Missing/Unwritable Files:** Must gracefully handle and exit with code 3. [cite: 110]
* [cite_start]**Empty Password:** Must reject and exit with code 4. [cite: 125]
* [cite_start]**Testing:** Final decrypted file must be **byte-for-byte identical** to the original input (`diff` must be clean). [cite: 116, 260]
