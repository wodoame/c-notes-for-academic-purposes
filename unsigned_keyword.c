/*
The "unsigned" keyword in C is used to specify that a variable of integer type
is non-negative. This type modifier changes the range of possible values that
can be stored in a variable, making it larger but only non-negative. The 
"unsigned" keyword can be applied to any integer type (e.g. "unsigned int", 
"unsigned long", "unsigned short", etc.).
Here's an example of how you could use the unsigned keyword in C:
*/

#include <stdio.h>

int main()
{
    unsigned int positiveInt = 42;
    printf("Positive integer: %u\n", positiveInt);
    return 0;
}

/*
In this code, we declare an unsigned int variable named positiveInt and assign it the value 42.
 Then, we use printf to print the value of positiveInt.
 The %u format specifier is used to print an unsigned int. The program outputs:

 Positive integer: 42


*/
