# Development Brief (Scaffold Stage)

This brief captures the expectations that guided the initial scaffold created via Prompt A.

- Provide headers with include guards and forward declarations only.
- Implement source files with no real business logic yet; use simple stubs that compile.
- Generate a Makefile capable of building all sources into the `c-note-encryptor` binary.
- Supply lightweight documentation references (pseudocode and flowchart placeholders).
- Ensure the repository structure matches the agreed project layout so subsequent prompts can
  build on a stable foundation.
- Parse CLI flags (-e/-d) and prompt for a non-empty password while routing into stubbed
  encrypt/decrypt functions so later work can focus on real I/O logic.
