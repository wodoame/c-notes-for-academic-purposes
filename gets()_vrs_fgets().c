/*
ME: what is the difference between gets() and fgets() in c
AI: gets() is a dangerous function because it doesn't limit the amount of input that 
it reads, leading to buffer overflows. fgets() is safer as it takes a maximum limit of characters 
to be read as an argument and adds a null terminator to the string.

ME: write some code to illustrate
AI:

Here's an example to illustrate the difference between gets() and fgets() in C:
*/

#include <stdio.h>
#include <string.h>

#define BUFSIZE 10

int main() {
    char buffer1[BUFSIZE];
    char buffer2[BUFSIZE];

    printf("Using gets():\n");
    gets(buffer1);
    printf("You entered: %s\n\n", buffer1);

    printf("Using fgets():\n");
    fgets(buffer2, BUFSIZE, stdin);
    printf("You entered: %s\n", buffer2);

    return 0;
}


// This code will show you how the input from the user is stored differently in 
// two different arrays buffer1 and buffer2 using gets() and fgets() respectively.