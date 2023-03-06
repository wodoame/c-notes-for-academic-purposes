#include <stdio.h>

int main() {
   FILE *fp;
   char buffer[255];

   // open file for reading
   fp = fopen("input.txt", "r");

   // check if file was opened successfully
   if(fp == NULL) {
      printf("Error opening file!\n");
      return 1;
   }

   // read data from file
   fgets(buffer, 255, (FILE*)fp);

   // print the data
   printf("%s\n", buffer);

   // close file
   fclose(fp);

   // indicate successful completion of program
   return 0;
}

// The program begins by including the standard input-output library "stdio.h".

// The main function is defined and takes no arguments.

// A file pointer variable "fp" is declared.

// A character array "buffer" is defined to store the data read from the file.

// The file "input.txt" is opened in read mode using fopen() function.

// The file pointer returned by fopen() is checked for NULL, which indicates that the file was not opened successfully.

// If the file was not opened successfully, an error message is printed and the program returns with an error code of 1.

// If the file was opened successfully, the data is read from the file using the fgets() function and stored in the buffer.

// The data stored in the buffer is printed to the console using printf() function.

// The file is closed using fclose() function.

// The program returns with a success code of 0.
