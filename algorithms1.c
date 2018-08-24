
//Do not forget to pass "-lm" option to compiler in order to link external libraries.
#include <stdio.h>
#include <stdlib.h> //prototype for abs() function
#include <math.h> // Для использования математических функций
#include <stdlib.h> // Для использования генератора случайных чисел
#include <sys/time.h>


char pi[100] ="1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679"; //100 digits of PI after comma. Used in random function. 

void solution14 ();
void solution13 ();
void solution12 ();
void menu ();

int main ()
{
    int sel = 0;
    do
    {
        menu ();
        scanf ( "%i" , & sel );
        switch ( sel)
        {
            case 1:
                solution14 ();
                break;
            case 2:
                solution13 ();
                break;
            case 3:
                solution12 ();
                break;
            case 4:
                solution11 ();
                break;
            case 5:
                solution10 ();
                break;
            case 6:
                solution9 ();
                break;
            case 7:
                solution8 ();
                break;                                                                    
            case 8:
                solution7 ();
                break;
            case 0:
                printf ( "Bye-bye" );
                break;
            default:
                printf ( "Wrong selected\n" );
        }
    } while ( sel != 0 );
return 0;
}

// ----------help functions
int countDigits ( int x) //count digits in a number 
{
    int result = 0;
    while ( x > 0)
    {
        result++;
        x = x / 10;
    }
    return result;
}

int sumDigits ( int x) //calculates summ of digits in a number
{
    int result = 0;
    while ( x > 0)
    {
        result = result + x % 10;
        x = x / 10;
    }
    return result;
}

long getMicrotime() //get current time in microseconds (somehow getting negative values under tests, thats why abs() used )
{
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return abs(currentTime.tv_sec * (int)1e6 + currentTime.tv_usec);
}

int myRandom()
{
    int mrnd;
    long a = getMicrotime(); //10 digits
    int b = a%10; //length. Max 9.
    int c = sumDigits(a) -17; //Offset. Max 90
    char part[b];
    for ( int i = c; i < c+b; i++ )  //choose part of PI of length b with offset c
    {
        part[i-c] = pi[i];
    }
    sscanf(part, "%d", &mrnd); //here MD5 function could be
    /*Конечно, в конце функции по-хорошему надо делать нормализацию данных. MD5 может быть максимум 32 символа.
    Ещё неплохо бы добавить зависимость от какой-то физической случайной величины. Самое простое - это пинг с хорошей точностью до какого-нибудь сервера.
    Ради сохранения совместимости и простоты не стал подключать сторонние библиотеки для функций вычисления MD5 и ping.
    Функция выдаёт случайные значения в неопределённом диапазоне.*/
    return mrnd;
}

double findMax (double a[])
{
  double max = 0;
  int len = -1;
  for (int i = 0; a[i]; i++)
    {
        len++;
    }
  for (int i = 0; i < len; i++)
    {
      if (a[i] > max)
	    max = a[i];
    }
  return max;
}

//---------------end of help functions

void solution14 ()
{
    printf ( "Solution 14\n" );
    printf ( "Автоморфные числа.\n");
    
    int n;     
    printf ( "Input an upper limit:" );
    scanf ( "%d", &n );
    for (int i = 0 ; i < n ; i ++)
    {
        if ( i == (i*i)%(int)pow(10, countDigits(i)))
            printf ( "%i " , i );
    }
}
void solution13 ()
{
  printf ( "Solution 13\n" );
  printf ( "Написать функцию, генерирующую случайное число от 1 до 100.\n" );
  
  // Решение ... задание решено в методичке!
  srand ( time ( NULL ));
  printf ( "%d\n" , rand () % 100 + 1 ); //... от 1 до 100
  // Попробовал написать свой алгоритм генератора псевдо случайных чисел:
  // 1. Получить текущее время. Запомнить в переменную А. 
  // 2. Последняя цифра числа А -> В.
  // 3. Посчитать сумму цифр А вычесть 17 и записать в С.
  // 4. Из числа Пи выделить последовательность длиной В со смещением С записываем -> D.
  // 5*. дополнительно можем ещё посчитать MD5 числа D
    printf ("My random: %d\n", myRandom() );
}
void solution12 ()
{
    printf ( "Solution 12\n" );
    printf ( "Написать функцию нахождения максимального из трех чисел.\n" );
    
    //Universal function to find max value. Artificially limited to the task.
    int arrSize = 2;		// size of array
    double arr[arrSize];
    for (int i = 0; i <= arrSize; i++)
      {
        printf ("Input number %d", i + 1);
        printf (": ");
        scanf ("%lf", &arr[i]);
      }
    printf ("Max value is: %lf", findMax (arr));         
    
    
}
void solution11 ()
{
    printf ( "Solution 11\n" );
    printf( "С клавиатуры вводятся числа, пока не будет введен 0.\n");
    printf( "Подсчитать среднее арифметическое всех положительных четных чисел, оканчивающихся на 8.\n" );
    
    int counter, sum;
    int num = 1; //this number will not be counted as it does not fulfill criteria
    double average;
    printf ("Enter 0 to exit.\n");
    while (num !=0)
    {
        printf ( "Enter a number: " );
        scanf ( "%d" , &num );
        if (num > 0 && num%10 == 8)   //no need to check for odd
        { 
            sum = sum + num;
            counter ++;
        }
    }
    if ( counter != 0)
    {
        average = sum / counter;
        printf ( "Average of positives ends with 8 is %g\n" , average );
    }
    else
    {
        printf ( "No valid numbers were entered" );
    }
}
void solution10 ()
{
    printf ( "Solution 10\n" );
    printf( "Дано целое число N (> 0). Oпределить, имеются ли в записи числа N нечетные цифры\n");
    
    int num, i;
    int res=1;
    int found = 0;
    printf ( "Enter a number: " );
    scanf ( "%d" , &num );
    for (i = 0; (num > 1 || num < -1); i++) //make cycle until N larger +/-1
    {
        res = num%10;
        num = num/10;
        if (res%2 == 0)
        {
            found = 1;
            break;    
        } 
    }
    if (found ==1)
    {
        printf ("\nFound at position %d", i+1);
    }
    else
    {
        printf ("\nEven values were not found");
    }
}
void solution9 ()
{
    printf ( "Solution 9\n" );
    printf ( "Даны целые положительные числа N и K. \n");
    printf ( "Используя только операции сложения и вычитания, найти\n");
    printf ( "частное от деления нацело N на K, а также остаток от этого деления.\n");
    // n / k = q (r) -> n = k * q + r
    
    int n, k;
    int q = 0; //quotient

    printf ( "Enter number N: " );
    scanf ( "%d" , &n );
    printf ( "Enter number K: " );
    scanf ( "%d" , &k );
    while (n >= k)
    {
        n = n - k;  //will get residual here
        q = q + 1;
    }
    printf ("n/k = %d (%d)", q, n); 
    
}
void solution8 ()
{
    printf ( "Solution 8\n" );
    printf ( "Ввести a и b и вывести квадраты и кубы чисел от a до b \n");

    int a, b;
    printf ( "Enter number A: " );
    scanf ( "%d" , &a );
    printf ( "Enter number B: " );
    scanf ( "%d" , &b );
    for (int i = a; i < b; i++)
    {
        printf ("%d", i);
        printf (" squared = %d\n", i*i);
        printf ("%d", i);
        printf (" cubed = %d\n", i*i*i);
    }
    
}

void solution7 ()
{
    printf ( "Solution 7\n" );
    printf ( "С клавиатуры вводятся числовые координаты двух полей \n");
    printf ( "шахматной доски (x1,y1,x2,y2). Требуется определить,\n");
    printf ( "относятся ли к поля к одному цвету или нет.\n");
    
    //sum of coordinates should be all odd or all even
    int x1, y1, x2, y2;
    printf ( "Enter number X1: " );
    scanf ( "%d" , &x1 );
    printf ( "Enter number Y1: " );
    scanf ( "%d" , &y1 );
    printf ( "Enter number X2: " );
    scanf ( "%d" , &x2 );
    printf ( "Enter number Y2: " );
    scanf ( "%d" , &y2 );
    if ( (x1+y1)%2 == (x2+y2)%2 )
    {
        printf ("Same color");
    }
    else
    {
        printf ("Different colours");
    }
}
void menu ()
{
  printf ("\nЗадания 1-6 выполнялись в рамках другого курса. Нет смысла копировать решения.\n");
  printf ( "1 - task14\n" );
  printf ( "2 - task13\n" );
  printf ( "3 - task12\n" );
  printf ( "4 - task11\n" );
  printf ( "5 - task10\n" );
  printf ( "6 - task9\n" );
  printf ( "7 - task8\n" );
  printf ( "8 - task7\n" );     
  printf ( "0 - exit\n" );
}
