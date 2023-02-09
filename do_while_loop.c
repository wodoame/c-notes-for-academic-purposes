#include <stdio.h>

int main() {
    int i = 1;  // initialize the counter variable

    /* The do-while loop will always execute the block of code
    at least once, and then repeat the loop as long as the 
    condition (i <= 10) is true */
    do {
        printf("%d\n", i);
        i++;
    } while (i <= 10);  // the condition to continue the loop

    return 0;
}
