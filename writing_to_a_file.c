#include <stdio.h>

int main() {
   FILE *fp;
   char data[] = "Hello, world!";
   
   // open file for writing
   fp = fopen("output.txt", "w");

   // check if file was opened successfully
   if(fp == NULL) {
      printf("Error opening file!\n");
      return 1;
   }

   // write data to file
   fputs(data, fp);

   // close file
   fclose(fp);

   // indicate successful completion of program
   return 0;
}

// The program begins by including the standard input-output library "stdio.h"

// The main function is defined and takes no arguments.

// A file pointer variable "fp" is declared.

// A character array "data" is defined and initialized with a string "Hello, world!".

// The file "output.txt" is opened in write mode using fopen() function.

// The file pointer returned by fopen() is checked for NULL, which indicates that the file was not opened successfully.

// If the file was not opened successfully, an error message is printed and the program returns with an error code of 1.

// If the file was opened successfully, the data in the character array "data" is written to the file using the fputs() function.

// The file is closed using fclose() function.

// The program returns with a success code of 0.











