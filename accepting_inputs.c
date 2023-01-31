/*
ME: 
how can you accept inputs in c programs
*/

/*
AI:
In C, you can accept inputs using the following functions:

1. scanf()
2. gets()
3. fgets()
4. getchar()
*/

/*
Here are code examples for each function:

1. scanf():
*/

#include <stdio.h>

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("You entered: %d", number);
    return 0;
}

/*
2. gets():
*/

#include <stdio.h>

int main()
{
    char name[20];
    printf("Enter your name: ");
    gets(name);
    printf("Your name is: %s", name);
    return 0;
}

/*
3. fgets():
*/

#include <stdio.h>

int main()
{
    char name[20];
    printf("Enter your name: ");
    fgets(name, 20, stdin);
    printf("Your name is: %s", name);
    return 0;
}

/*
4. getchar():
*/

#include <stdio.h>

int main()
{
    char c;
    printf("Enter a character: ");
    c = getchar();
    printf("You entered: %c", c);
    return 0;
}
