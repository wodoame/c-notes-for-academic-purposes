/*
ME: what does #define do in C
AI: #define is a preprocessor directive in C that allows you to define macros, which are shorthand notations for a sequence of statements or values.
*/

/*
ME: write a code example
AI: Here is an example of using #define to create a constant in C:
*/

#define PI 3.14159265
#define RADIUS 10

int main() {
  float circumference = 2 * PI * RADIUS;
  printf("Circumference of a circle with radius %d is %f\n", RADIUS, circumference);
  return 0;
}

// This program calculates and prints the circumference of a circle with a radius of 10. 
// The constant value of PI is defined using the #define directive, and the radius of the 
// circle is also defined as a constant using #define.
// These constants can then be used in the code, just like any other variable.

