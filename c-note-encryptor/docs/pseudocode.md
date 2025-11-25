# Pseudocode Placeholder

```
start program
  if args are invalid
    show usage text
    exit with error code
  determine mode from -e or -d flag
  capture input and output paths
  prompt for password
  if password empty
    print error and exit
  if mode is encrypt
    call encrypt_file stub
  else
    call decrypt_file stub
  report returned status
end program
```
