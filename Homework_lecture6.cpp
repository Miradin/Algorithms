//Alexander Zhigunov
//programming language: C++

/*
1. Реализовать простейшую хэш-функцию. На вход функции подается строка,
на выходе сумма кодов символов.
*/

#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

char s[1000]; //we have to define string length

long int checksum(char *s) //Here is a function for task 1
{
    long int result = 0;
    unsigned int i = 0;
    for (i = 0; i < strlen(s); i++)
    {
        result = result + int(s[i]);
    }
    printf("Entered line length is: %i\n", i);
    return result;
}

int main()
{
    printf("Enter a string: ");
    scanf("%s", s);
    printf("Calculated checksum is: %ld\n", checksum(s));
    return 0;
}
