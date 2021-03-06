
/*по дополнительному домашнему заданию:
Вариантов решения несколько... Конкретные реализации зависят от нюансов условия задачи, таких, как, например, надо ли различать команды участников, может ли команда быть пуста и т.д.
Изначально думал про идентичные группы и перемещать по одному участнику, но решил сделать более универсальное решение.
Реализовал самое простое решение (возможно, не самое оптимальное). Немного упрощу задачу, для объяснения алгоритма:
У нас есть например 5 участников. нам надо их разделить на 3 группы, пустые группы возможны, группы тоже имеют свое название.
1. Пусть людей зовут A, B, C, D, E (с таким упрощением уникальных имен может быть более 100 000, если использовать Юникод). Создадим массив длиной 5.
2. Начальное положение: все люди находятся в группе 1
3. Дополним группы 2 и 3 "людьми-пустышками"... ничего не значащим символом ".". Длина равна количеству участников (длине массива участников)
4. Делаем новый массив, которая в себе содержит сумму людей из всех групп. Получаем: ABCDE.......... (M+M*N)
5. Используем алгоритм перестановок символов в слове на новом массиве (пермутация). Получаем все возможные варианты строк
6. Разбиваем каждую полученную строку обратно на 3 равные группы.

Если немного изменить задание и сказать, что группы могут быть пусты, и даже некоторые участники могут не участвовать... то алгоритм лишь немного изменится, а именно:
в шаге 4 добавляем в конец массива ещё "людей-пустышек" числом 5-1.

Если опять немного изменить задание и сказать, что пустых групп быть не должно... ну, чтож, просто делать проверку и исключать из выборки строки, где хотябы 1 массив на шаге 6 состоит только из символов ".".

Понятно, что если вдруг задание будет подразумевать идентичные группы, то в данном контексте можно сделать проверку в конце на наличие дубликатов (или менять алгоритм).

Недостатки: алгоритм выдаёт дублирующие значения. Например, ABCD .... .... = ABDC .... ....*/


//
// An example of how to generate permutations
// using Heap's algorithm
//
#include <stdio.h>
#include <string.h>

// an array of stuff to permute
// given number of people and names
const int n = 4; //number of people
char a[n+1] = "abcd"; //char array is null terminated
const int g = 3; //number of groups
char sim[n*g]=""; //new line

void print() //only output magic here
{
    for (int j=0; j<g; j++) //visually devide string into g groups
    {
        for(int i=j*n; i<n*(j+1); i++)
            printf("%c ", sim[i]);
        printf("   ");
        
    }
    printf("\n");
}

int main(int argc, char * argv[])
{
  printf("In total we have %d people and %d groups.\n", n, g);
  for (int i=0; i < (n*g); i++)
  {
      if (i<n) sim[i] = a[i];
      else sim[i] = '.';
      
  }
  printf("sim: %s\n", sim);
  // make an idx array filled with zero
  int idx[n*g];
  for(int i=0; i < n*g; i++)
    idx[i] = 0;

  print();

  // heap's algorithm, iterative version
  for (int i=1; i < n*g;) {
    if (idx[i] < i) {
      int swap = i % 2 * idx[i];
      int tmp = sim[swap];
      sim[swap] = sim[i];
      sim[i] = tmp;
      print();
      idx[i]++;
      i = 1;
    } else {
      idx[i++] = 0;
    }
  }
  return 0;
}
