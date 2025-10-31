# Password-Protected Note Encryption Tool (Scaffold)

This repository currently contains the **scaffolding** for a C-based command-line
utility that will encrypt and decrypt text notes using a password-driven XOR
scheme. The implementation is intentionally incomplete at this stage; the goal
was to establish the directory layout, shared data structures, and documentation
artifacts referenced in `docs/DEV_BRIEF.md`.

## Repository Layout

```
c-note-encryptor/
├─ src/
│  ├─ main.c
│  ├─ encrypt.c
│  └─ loglist.c
├─ include/
│  ├─ encrypt.h
│  ├─ types.h
│  └─ loglist.h
├─ docs/
│  ├─ DEV_BRIEF.md
│  ├─ pseudocode.md
│  └─ flowchart.txt
├─ tests/
│  ├─ empty.txt
│  ├─ small.txt
│  └─ utf8.txt
├─ Makefile
└─ README.md
```

## Building the Scaffold

```
make
./c-note-encryptor
```

The resulting executable only prints a placeholder message. Future tasks will
introduce argument parsing, password handling, and file transformation logic.
