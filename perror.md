perror prints a human-readable error message to stderr based on the current errno.

What it does:
- Output format: "<prefix>: <system error message>\n"
- Prefix is the string you pass (or prints just the message if prefix is NULL or empty).
- Uses errno (thread-local) to choose the message; does not modify errno.

How to use:
- Call it right after a library call fails (the failing call sets errno).
- Typical pattern:

````c
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

FILE *f = fopen("missing.txt", "r");
if (!f) {
    perror("fopen");
    // e.g., prints: fopen: No such file or directory
}

void *p = malloc(1024 * 1024 * 1024UL);
if (!p) {
    perror("malloc");
    exit(EXIT_FAILURE);
}
````

Custom formatting alternative:
````c
#include <errno.h>
#include <string.h>

fprintf(stderr, "malloc failed: %s\n", strerror(errno));
````

Notes:
- errno is only meaningful after a failure; it isn’t cleared on success.
- perror reports C runtime errors (errno). For Windows API calls (GetLastError), use FormatMessage, not perror.
