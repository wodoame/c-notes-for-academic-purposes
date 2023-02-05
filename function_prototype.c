/* In C, a function prototype is a declaration of a function that provides information about the function 
to the compiler before the function is actually defined. 

A function prototype includes the function's return type, name, and the number and types of its parameters. 
It is used to ensure that the function is called correctly with the correct number and types of arguments. 

A function prototype can be placed in a header file to make it available to multiple source files, 
or it can be included before the main function in a single source file. 

Example: 
*/

int max(int a, int b); 

// This is a function prototype for a function named `max` that returns an `int` and takes two `int` parameters. 
// The function definition for this function might look like this: 

int max(int a, int b) { 
  return (a > b) ? a : b; 
}
/*
Note that the parameter names in the function prototype are optional, but they are helpful for documenting the 
function's purpose and usage. */
