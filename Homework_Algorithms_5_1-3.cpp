//Alexander Zhigunov
//Programming language: C++

/*
1. Реализовать перевод из 10 в 2 систему счисления с использованием стека.
3. Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.

Например: (2+(2*2)) или [2/{5*(4+7)}]
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

#define T int
#define MaxN 1000


T Stack[MaxN];

int N = -1;

void push(T i)
{
    if (N < MaxN)
    {
        N++;
        Stack[N] = i;
    }
    else
        printf("Stack overflow");
}

T pop()
{
    if (N != -1)
        return Stack[N--];
    else
        printf("Stack is empty");
    return 0;
}


void task1()
{
    printf("\nTask 1: Реализовать перевод из 10 в 2 систему счисления с использованием стека.\n");
    int dec, bin;
    printf("Please, enter a number (decimal): ");
    scanf("%i", &dec);
    while (dec>0)
    {
        bin = dec%2;
        dec = dec/2;
        push(bin); //push into stack
    }
    printf("Result: \n");
    while(N != -1)
        printf("%d",pop()); //read from stack. This should empty the stack as well.

}

void task3()
{
    printf("\nTask 3: Написать программу, которая определяет, является ли введенная скобочная последовательность правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{.\n");
    char my_expr;
    char p;
    int err = 0;
    printf("Please, enter an expression (q to exit): ");
    while (my_expr != 'q')
    {
        scanf("%c", &my_expr);
        if (my_expr == '(' || my_expr == '[' || my_expr == '{' || my_expr == '<')
            push(my_expr); //push into stack
        else
            switch (my_expr)
            {
            case ')':
                p = pop();
                if (p != '(')
                    err = 1;
                break;
            case ']':
                p = pop();
                if (p != '[')
                    err = 1;
                break;
            case '}':
                p = pop();
                if (p != '{')
                    err = 1;
                break;
            case '>':
                p = pop();
                if (p != '<')
                    err = 1;
                break;
            default:
                break;
            }
    }
    if (N != -1 || err == 1)
        printf("Error");
    else
        printf("Entered expression is correct");

}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "rus"); //Changing encoding to get cyrillic
    task1();
    task3();
    return 0;
}
