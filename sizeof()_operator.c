#include <stdio.h>

int main() {
    int num = 10;
    char letter = 'A';
    float decimal = 3.14;

    // Use the sizeof operator to get the size of each variable in bytes
    printf("Size of int: %ld bytes\n", sizeof(num));
    printf("Size of char: %ld bytes\n", sizeof(letter));
    printf("Size of float: %ld bytes\n", sizeof(decimal));

    return 0;
}
/*
This code demonstrates the use of the sizeof operator in C. The sizeof operator 
returns the size of its operand in bytes. In this example, the sizeof operator 
is used to get the size of an int, a char, and a float variable. The sizes are then printed using printf.

It's important to note that the value returned by sizeof is platform-dependent
 and can vary on different systems. However, the size of a specific data type (such as int or char) 
is usually standardized across platforms and can be found in the C standard library.
*/
