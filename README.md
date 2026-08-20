# Custom Linux Commands in C

A collection of Unix/Linux command-line utilities implemented from scratch in C, without relying on the actual system binaries. Each command is built as a standalone C program that uses low-level system calls to reproduce the core behavior of its real-world counterpart.

## About

This project recreates common Linux shell commands to understand how they work under the hood — file system operations, system calls, and process handling. Instead of calling the built-in `/bin/ls`, `/bin/cp`, etc., each program directly uses system calls like `open()`, `read()`, `write()`, `stat()`, `opendir()`, `unlink()`, and `rename()` to perform the same task.

## Commands Implemented

| Command | Source File(s)                    | Description |
|---------|------------------------------------|-------------|
| `ls`    | `Command_ls.c`, `Command_ls2.c`   | List files and directories |
| `pwd`   | `Command_pwd.c`                   | Print current working directory |
| `cat`   | `Command_cat.c`                   | Display contents of a file |
| `cp`    | `Command_cp.c`                    | Copy files |
| `mv`    | `Command_mv.c`                    | Move/rename files |
| `rm`    | `Command_rm.c`                    | Remove files |
| `cd`    | `Command_cd.c`                    | Change current directory |
| `touch` | `Command_touch.c`                 | Create empty files / update timestamps |
| `stat`  | `Command_stat.c`, `Command_stat2.c` | Display file/inode status information |
| `uname` | `Command_uname.c`                 | Print system information |
| `ps`    | `Command_ps.c`                    | List running processes |


## Tech Stack

- **Language:** C
- **Platform:** Linux
- **Concepts used:** System calls, file I/O, directory handling, process/file management

## Getting Started

### Prerequisites
- A Linux environment (or WSL)
- GCC compiler

### Build

Each command is compiled as a separate program:

```bash
gcc Command_ls.c   -o lsx
gcc Command_pwd.c  -o pwdx
gcc Command_cat.c  -o catx
gcc Command_cp.c   -o cpx
gcc Command_mv.c   -o mvx
gcc Command_rm.c   -o rmx
gcc Command_cd.c   -o cdx
gcc Command_touch.c -o touchx
gcc Command_stat.c -o statx
gcc Command_uname.c -o unamex
gcc Command_ps.c   -o psx
```

### Usage

Run any compiled binary just like the real command:

```bash
./lsx
./pwdx
./catx filename.txt
./cpx source.txt destination.txt
./mvx old_name.txt new_name.txt
./rmx filename.txt
./cdx some_directory
./touchx newfile.txt
./statx filename.txt
./unamex
./psx
```

## Project Structure

```
.
├── Command_cat.c
├── Command_cd.c
├── Command_cp.c
├── Command_ls.c
├── Command_ls2.c
├── Command_mv.c
├── Command_ps.c
├── Command_pwd.c
├── Command_stat.c
├── Command_stat2.c
├── Command_touch.c
├── Command_uname.c
└── README.md
```

## What I Learned

- How Linux system calls work under the hood
- File descriptor management and error handling in C
- Directory traversal using `opendir()`/`readdir()`
- Difference between library functions and raw system calls

## Future Improvements

- Add support for command-line flags/options (e.g. `ls -l`, `rm -r`)
- Add more commands (`mkdir`, `touch`, `grep`, etc.)
- Combine into a single custom shell (REPL)