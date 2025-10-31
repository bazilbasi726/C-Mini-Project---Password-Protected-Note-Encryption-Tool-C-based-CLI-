# Pseudocode

```
main():
    parse CLI arguments for mode and file paths
    if parsing fails:
        print usage message
        exit with error code

    prompt user for password
    initialize Flags structure to capture validation status

    populate NoteInfo with input path, output path, mode
    call transform_note(NoteInfo, password)
    print placeholder success message
```

```
transform_note(info, password):
    (stub) return success without modifying files
```
