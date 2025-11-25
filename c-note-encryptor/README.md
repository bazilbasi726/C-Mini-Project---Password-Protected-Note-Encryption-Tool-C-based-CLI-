# c-note-encryptor Scaffold

This repository contains the starter layout for the password-protected note encryption tool.
It currently ships with placeholder implementations so future steps can focus on incremental
feature development.

## Building

```bash
make
```

This produces the `c-note-encryptor` executable in the project root.

## Running

The scaffold accepts encrypt or decrypt flags but the underlying logic is still stubbed:

```bash
./c-note-encryptor -e input.txt output.enc
./c-note-encryptor -d input.enc output.txt
```

The program prompts for a non-empty password, forwards control to placeholder
`encrypt_file`/`decrypt_file` functions, and reports the returned status.

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
# C Note Encryptor

Placeholder README for the password-protected note encryption tool project.
