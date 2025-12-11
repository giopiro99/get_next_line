# 📝 Get_next_line

**Get_next_line** is a project from the **42 School** curriculum. The goal is to write a function that reads content from a file descriptor and returns it **line by line**.

While standard C provides `scanf` or `fgets`, this project explores the low-level logic of buffering, static variables, and dynamic memory allocation to manage file I/O manually.

## 📑 Overview

The function reads from a file descriptor (whether it's a standard text file, standard input, or a network socket) and returns the next line found, including the trailing newline character (`\n`) if present.

### Prototype
```bash
char *get_next_line(int fd);

Parameters
fd: The file descriptor to read from.

Return Value
Read line: Correct behavior.

NULL: Nothing else to read (EOF) or an error occurred.
```

### ✨ Features
```text
Buffering: Reads data in chunks defined by BUFFER_SIZE to optimize system calls.

Persistence: Uses static variables to remember the state of the file descriptor between function calls (saving the "leftover" characters after a newline).

Dynamic Memory: Allocates exactly enough memory for the line returned, preventing buffer overflows.

Multiple File Descriptors (Bonus): Can read from multiple FDs essentially simultaneously without losing the reading thread of any of them.
```

### 🛠️ Implementation Logic
```text
Read: The function reads BUFFER_SIZE bytes from the file descriptor into a temporary buffer.

Stash: This buffer is joined to a static "stash" string.

Check: It checks if a newline (\n) exists in the stash.

If No: Repeat step 1 (Read more).

If Yes:

Extract the line up to \n.

Update the static stash to contain only the remaining characters after the \n.

Return the line.
```

### 🚀 Installation & Usage
```text
1. Requirements
GCC or Clang compiler.
Standard C libraries.

2. Compilation
To use get_next_line in your project, you must compile your source files with the library files. You must also define the buffer size using the -D flag.
```

```bash
# Example with a main.c file and a buffer size of 42
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c
⚠️ Note: If BUFFER_SIZE is not defined, the behavior might be undefined or default to a fixed value depending on your header file.

3. Usage Example
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("file.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line); // Don't forget to free the line!
    }
    close(fd);
    return (0);
}
```
### ⭐️ Bonus Part
```text
The bonus implementation allows managing multiple file descriptors at the same time.

You can call get_next_line on fd 3, then on fd 4, then back on fd 3 without losing the position or the buffer content of either file.

This is achieved by using a static array of pointers (instead of a single static pointer), indexed by the file descriptor number.
```
```bash
To compile the bonus:
gcc -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c
```

🧠 What I Learned
Static Variables: Understanding how variables effectively "live" in the data segment of the memory, persisting their value across function calls.

File Descriptors: Deep dive into how the OS identifies open files.

Memory Management: Strict management of malloc and free to prevent leaks, especially when manipulating strings inside loops.

Macro Definitions: Using compiler flags (-D) to modify program behavior at compile time.
