/*
ME: what does <ctype.h> provide in c programming

AI: 
<ctype.h> is a header file in C programming that provides functions for 
classifying and transforming individual characters. 

Some of the functions defined in this header file include:
- isalpha(int c): returns non-zero if `c` is an alphabetic character
- isdigit(int c): returns non-zero if `c` is a decimal digit
- isalnum(int c): returns non-zero if `c` is an alphabetic character or a decimal digit
- toupper(int c): returns the uppercase equivalent of `c` if `c` is an lowercase alphabetic character
- tolower(int c): returns the lowercase equivalent of `c` if `c` is an uppercase alphabetic character

These functions can be useful for validating user input, checking the type of a character, or converting 
characters to a specific case. */

// ME: write example codes for each of the above examples

#include <ctype.h>
#include <stdio.h>

int main() {
  char c;

  // Example: isalpha
  c = 'A';
  if (isalpha(c)) {
    printf("'%c' is an alphabetic character\n", c);
  }

  // Example: isdigit
  c = '9';
  if (isdigit(c)) {
    printf("'%c' is a decimal digit\n", c);
  }

  // Example: isalnum
  c = 'a';
  if (isalnum(c)) {
    printf("'%c' is an alphabetic character or a decimal digit\n", c);
  }

  // Example: toupper
  c = 'a';
  printf("Uppercase equivalent of '%c': '%c'\n", c, toupper(c));

  // Example: tolower
  c = 'A';
  printf("Lowercase equivalent of '%c': '%c'\n", c, tolower(c));

  return 0;
}
