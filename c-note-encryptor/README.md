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

```bash
./c-note-encryptor
```

At this stage, the executable only prints usage information because the functional logic is not
yet implemented.

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
