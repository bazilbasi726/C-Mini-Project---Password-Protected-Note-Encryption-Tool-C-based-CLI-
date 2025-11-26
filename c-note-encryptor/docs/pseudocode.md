# Pseudocode Placeholder

```
start program
  if args are invalid
    show usage text
    exit with error code 2
  determine mode from -e or -d flag
  capture input and output paths
  prompt for password
  if password empty
    print error and exit with code 4
  create an empty log list
  append mode selection to log
  decide key as first character of password
  open input for reading, output for writing
  if either fails, exit with code 3
  if input path equals output path, exit with code 2
  if input file is empty, log the condition and exit success after closing files
  optional: preview first token with fscanf/fprintf for logging
  loop over each byte from input
    XOR byte with key
    write result to output
    if write fails, exit with code 3
  log bytes processed and print log list
  close files
  return success code 0
end program
```
