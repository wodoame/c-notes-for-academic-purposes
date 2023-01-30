/* 

switch statement is a control structure that allows for a 
clear and concise way of writing a multi-way branch statement.
The switch statement in C tests the value of an expression and jumps 
to the corresponding case label based on the value.
A break statement is used to terminate the execution of a particular case. 
If there is no break, then execution continues to the next case.
A default case can be used to provide a default behavior
 if none of the cases match the expression value.
 
 */

#include <stdio.h>

int main() {
  int day = 4;
  /* switch statement syntax */
  switch(day) {
    case 1: 
      printf("Monday\n");
      break;
    case 2:
      printf("Tuesday\n");
      break;
    case 3:
      printf("Wednesday\n");
      break;
    case 4:
      printf("Thursday\n");
      break;
    case 5:
      printf("Friday\n");
      break;
    case 6:
      printf("Saturday\n");
      break;
    case 7:
      printf("Sunday\n");
      break;
    /* default case is executed if no cases match */
    default:
      printf("Invalid day\n");
      break;
  }

  return 0;
}

// Output:
// Thursday
