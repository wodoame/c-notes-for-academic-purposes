Key differences:

- Parameters:
  - malloc(size): allocates size bytes.
  - calloc(n, size): allocates n * size bytes.
- Initialization:
  - malloc: memory is uninitialized (indeterminate bytes).
  - calloc: memory bytes are set to 0. This makes integers 0; pointers become NULL on most platforms (the C standard only guarantees zeroed bytes, not semantic zero for every type).
- Overflow check:
  - calloc can fail safely if n * size overflows; with malloc you must check yourself.
- Performance:
  - malloc is typically faster for small allocations.
  - calloc can be as fast or faster for large blocks due to zeroed pages from the OS/allocator.

When to use:
- Use malloc when you will immediately write every byte.
- Use calloc when you want zero-initialized memory (e.g., structs with pointers).

Examples:

````c
// malloc + manual init
Node* n = malloc(sizeof *n);
if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
n->data = value;
n->left_child = NULL;
n->right_child = NULL;

// calloc (auto-zeroed)
Node* n = calloc(1, sizeof *n);
if (!n) { perror("calloc"); exit(EXIT_FAILURE); }
n->data = value;            // children already NULL
````
