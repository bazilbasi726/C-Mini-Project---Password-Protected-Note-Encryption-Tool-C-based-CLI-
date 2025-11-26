# c-note-encryptor Scaffold

This repository contains the starter layout for the password-protected note encryption tool.
It now performs the actual XOR transform (keyed by the first character of the password)
while keeping the code structure simple for incremental development.

## Building

```bash
make
```

This produces the `c-note-encryptor` executable in the project root.

## Running

The tool encrypts/decrypts using the first character of the password as the XOR key:

```bash
./c-note-encryptor -e input.txt output.enc
./c-note-encryptor -d input.enc output.txt
```

The program prompts for a non-empty password, validates arguments, and performs a
byte-wise XOR transform to produce encrypted or decrypted output. Status codes
returned to the shell:

- `0`: success
- `2`: invalid arguments (e.g., missing mode flag)
- `3`: I/O error (cannot open/read/write files)
- `4`: password error (empty or unreadable)

Additional behavior:

- Rejects identical input/output paths and reports why.
- Treats empty input files as a valid no-op (creates an empty output).
- Prints a simple linked-list log of steps (mode selection, file opens, byte counts)
  at program exit to demonstrate the self-referential structure requirement.

## Repository Layout

```
c-note-encryptor/
├── Makefile
├── README.md
├── docs/
│   ├── DEV_BRIEF.md
│   ├── flowchart.txt
│   └── pseudocode.md
├── include/
│   ├── encrypt.h
│   ├── loglist.h
│   └── types.h
├── src/
│   ├── encrypt.c
│   ├── loglist.c
│   └── main.c
├── tests/
│   ├── empty.txt
│   ├── small.txt
│   └── utf8.txt
└── input.txt
```
