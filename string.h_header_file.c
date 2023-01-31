/*
ME: what does the <string.h> header file provide in C

AI: The <string.h> header file in C provides various string handling functions, such as:
strcpy: Copy a string,
strcat: Concatenate two strings,
strlen: Get length of a string,
strcmp: Compare two strings, 
memset: Fill memory with a constant byte, 
memcpy: Copy memory block,
strstr: Locate a substring and others.
*/

/*
ME: write code examples for each

AI: 
Here are code examples for each of the string handling functions in the <string.h> header file in C:
*/
// strcpy: Copy a string
#include <stdio.h>
#include <string.h>

int main()
{
    char src[40];
    char dest[100];

    memset(dest, '\0', sizeof(dest));
    strcpy(src, "This is source");
    strcpy(dest, src);

    printf("Final destination string : %s\n", dest);

    return 0;
}

// strcat: Concatenate two strings
#include <stdio.h>
#include <string.h>

int main()
{
    char dest[100] = "Hello ";
    char src[40] = "World";

    strcat(dest, src);

    printf("Final destination string : %s\n", dest);

    return 0;
}

// strlen: Get length of a string
#include <stdio.h>
#include <string.h>

int main()
{
    char str[40];

    strcpy(str, "This is string.h library function");
    int len = strlen(str);

    printf("Length of |%s| is %d\n", str, len);

    return 0;
}

// strcmp: Compare two strings
#include <stdio.h>
#include <string.h>

int main()
{
    char str1[15];
    char str2[15];
    int result;

    strcpy(str1, "abc");
    strcpy(str2, "abc");

    result = strcmp(str1, str2);

    if (result == 0)
        printf("Both strings are equal\n");
    else
        printf("Both strings are not equal\n");

    return 0;
}

// memset: Fill memory with a constant byte
#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];

    memset(str, '*', 7);
    str[7] = '\0';

    printf("%s\n", str);

    return 0;
}

// memcpy: Copy memory block
#include <stdio.h>
#include <string.h>

int main()
{
    char src[40] = "This is source";
    char dest[100];

    memcpy(dest, src, strlen(src)+1);
    printf("Final destination string : %s\n", dest);

    return 0;
}

// strstr: Locate a substring
#include <stdio.h>
#include <string.h>

int main()
{
    char str[40] = "This is a simple string";
    char *pch;

    pch = strstr(str, "simple");
    strncpy(pch, "sample", 6);
    printf("Final string after replacing: %s\n", str);

    return 0;
}