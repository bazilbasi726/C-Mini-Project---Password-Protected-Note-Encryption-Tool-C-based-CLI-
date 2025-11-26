# Pseudocode Placeholder

```
start program
  if args are invalid
    show usage text
    exit with error code 2
    exit with error code
  determine mode from -e or -d flag
  capture input and output paths
  prompt for password
  if password empty
    print error and exit with code 4
  decide key as first character of password
  open input for reading, output for writing
  if either fails, exit with code 3
  optional: preview first token with fscanf/fprintf for logging
  loop over each byte from input
    XOR byte with key
    write result to output
    if write fails, exit with code 3
  close files
  return success code 0
    print error and exit
  if mode is encrypt
    call encrypt_file stub
  else
    call decrypt_file stub
  report returned status
end program
```
