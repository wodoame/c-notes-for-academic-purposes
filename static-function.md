In C, static on a function gives it internal linkage: the symbol is visible only within that source file (translation unit).

Why use it:
- Encapsulation: create_node is an internal helper, not part of the public API.
- Avoid name clashes: other files can have their own create_node.
- Allows the linker/compiler to drop it if unused and sometimes optimize more aggressively.

What it is not:
- It does not make the function “persist” like a static local variable.
- It does not change runtime behavior; only linkage/visibility.

If you need to call it from other .c files, remove static and put a prototype in a header:

````c
// tree.h
typedef struct Node Node;
Node* create_node(int value);

// tree.c
#include "tree.h"
struct Node { int data; Node* left_child; Node* right_child; };
Node* create_node(int value) { /* ... */ }
````
