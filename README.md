# get_next_line
a function that take a File Descriptor and read one line at a time

get_next_line is a function that reads a file descriptor line by line, returning each line one at a time. This project aims to improve file I/O handling and memory management in C.

## Features

- Reads from a given file descriptor until a newline (`\n`) or EOF is reached.
- Returns each line including the newline character (if present).
- Handles multiple file descriptors simultaneously (bonus part).
- Manages dynamic memory efficiently to avoid leaks and buffer overruns.
- Supports reading from standard input, files, or any valid file descriptor.
- Implements robust error checking and edge case handling.

## Purpose

The get_next_line project is designed to practice working with low-level file operations, dynamic memory allocation, and managing static variables to keep track of read buffers across function calls. The bonus part extends functionality to handle multiple file descriptors at once, increasing the utility of the function in real-world scenarios.

