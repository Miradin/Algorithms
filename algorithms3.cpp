/*
1. Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций.
2. *Реализовать шейкерную сортировку.
3. Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив. Функция возвращает индекс найденного элемента или -1, если элемент не найден.
4. *Подсчитать количество операций для каждой из сортировок и сравнить его с асимптотической сложностью алгоритма.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm> //for std::copy

double getUnixTime(void)
{
    struct timespec tv;

    if(clock_gettime(CLOCK_REALTIME, &tv) != 0) return 0;

    return (tv.tv_sec + (tv.tv_nsec / 1000000000.0));
}

void print(int N, int *a)
{
    for (int i = 0; i < N; i++)
        printf("%d  :  ", a[i]);
}

void * bub1(int N, int *b)    //Non-optimized Bubble sorting (desceding)
{
    int swap = 0;
    int ops = 0;
    for (int i = 0; i < N; i++)
    {
        ops++;
        for (int j = 0; j < N-1; j++)
        {
            ops++;
            if (b[j] < b[j+1])
            {
                swap = b[j]; 
                b[j] = b[j+1];
                b[j+1] = swap;
            }
        }
    }
    printf("There are %d operations in non-optimized Bubble sorting", ops);
}

void * bub2(int N, int *b)    //Optimized Bubble sorting (desceding)
{
    int swap = 0;
    int flag = 0;
    int ops = 0;
    for (int i = 0; i < N; i++)
    {
        ops++;
        flag = 0;
        for (int j = 0; j < N-1; j++)
        {
            ops++;
            if (b[j] < b[j+1])
            {
                swap = b[j];
                b[j] = b[j+1];
                b[j+1] = swap;
                flag = 1;
            }
        }
        if (flag == 0) break;;
    }
    printf( "There are %d operations in optimized Bubble sorting", ops );
}

void * shakerSort(int N, int *b)    //optimized Shaker sorting (asceding)
{
    int swap = 0;
    int flag = 0;
    int ops = 0;
    for (int i = 0; i < N/2; i++)
    {
        ops++;
        flag = 0;
        for (int j = i+1; j < N-i-1; j++)
        {
            ops++;
            if (b[j] > b[j+1])
            {
                swap = b[j];
                b[j] = b[j+1];
                b[j+1] = swap;
                flag = 1;
            }
        }
        for (int j = N - 2 - i; j > i; j--)
        {
            ops++;
            if (b[j] < b[j-1])
            {
                swap = b[j];
                b[j] = b[j-1];
                b[j-1] = swap;
                flag = 1;
                ops++;
            }
        }
        if (flag == 0) break;;
    }
    printf( "There are %d operations in optimized Shaker sorting", ops );
}

int binSearch (int N, int b[], int key)    //Binary search on asceding array as a function
{
    int left = 0;
    int right = N;
    int middle = 0;
    while(1)
    {
        middle = (left+right)/2;
        if (b[middle] > key) right = middle-1;
        if (b[middle] < key) left = middle+1;
        if (b[middle] == key) return middle;
        if (left > right) return -1;
    }
    
}

int main()
{
    double start_time, stop_time, difference; //variables to time functions
    
    int N = 0;
    int key = 0;
    printf( "Note1: Optimization of Bubble algorithm shows negligible improvement on true random data\n" );
    printf( "Note2: Timing usage is more correct in order to estimate function performance.\n" );
    printf( "Note3: Just to make some fun, both Bubble algorithms doing desceding ordering\n" );
    printf( "       while Shaker doing asceding. Thus performance is not 100% accurate\n" );
    printf( "       but close to that on big arrays, as we have random data.\n" );
    printf( "----------------------------------------------------------------------------------------\n" );
    printf( "Enter array length (put more than 100000 to see positive effect): " ); //array length
    scanf ( "%i" , &N );
    srand(time(NULL));
    int a[N]; //initialize array
    int b[N]; //for sorting. Should be reset after each sorting.

    for (int i = 0; i < N; i++) //fill up the array with random numbers
    {
        a[i] = rand()%100;

    }
    
    printf( "O(n^2) for sorting in the worst case is: %d\n", N*N);
    std:: copy(a, a+N, b);
    start_time = getUnixTime();
    bub1(N, b);
    stop_time = getUnixTime();
    difference = stop_time - start_time;
    printf( "\nPerformance of non-optimized bubble: %lf\n", difference );

    std:: copy(a, a+N, b);
    start_time = getUnixTime();
    bub2(N, b);
    stop_time = getUnixTime();
    difference = stop_time - start_time;
    printf( "\nPerformance of optimized bubble: %lf\n", difference );
    
    std:: copy(a, a+N, b);
    start_time = getUnixTime();
    shakerSort(N, b); //here we should do acceding sort in order to make classical Binary search
    stop_time = getUnixTime();
    difference = stop_time - start_time;
    printf( "\nPerformance of optimized shaker: %lf\n", difference );
    
    printf("\nAt this point we have an ordered array and thus can apply Binary search\n");
    printf( "----------------------------------------------------------------------------------------\n" );
    printf("Enter a number to search (0-99): ");
    scanf ( "%i" , &key );
    printf("\nNumber was found at position: %i\n", binSearch(N, b, key));
    
    //printf("Initial array: \n");
    //print(N, a);    
    //printf("\nOrdered array: \n");
    //print(N, b);

    return 0;
}
