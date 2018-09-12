//Alexander Zhigunov
//Programming language: C++

/*
3. ***Требуется обойти конём шахматную доску размером NxM, пройдя через все поля доски по одному разу. Здесь алгоритм решения такой же как и в задаче о 8 ферзях. Разница только в проверке положения коня.
*/

#include<stdlib.h>
#include <stdio.h>
#include <math.h>
#define N 5
#define M 5

int board[N][M];
int SearchSolution(int n, int x, int y);
int MoveAllowed(int x, int y);
int SolutionImpossible(int x, int y);
void Print(int n, int m, int a[N][M]);
void Zero(int n, int m, int a[N][M]);
int solutions = 0;

//массив с разрешенными ходами коня
int possible_moves[8][2]  = {
        {-2, -1},
		{-2,  1},
		{ 2, -1},
		{ 2,  1},
		{-1, -2},
        {-1,  2},
        { 1, -2},
        { 1,  2},
};

int main()
{
	Zero(N, M, board);
    int start_x = 0, start_y = 0;
    printf("Board size is %i X %i\n", N, M);
    printf("Enter starting point at X: ");
    scanf ( "%i" , &start_x );
    printf("Enter starting point at Y: ");
    scanf ( "%i" , &start_y );

    //проверка существования решения
    if (SolutionImpossible(start_x, start_y))
    {
        printf("Solution impossible within given parameters.");
        return 0;
    }
	SearchSolution(1, start_x, start_y);
	printf("\nIn total %i solutions were found.\n", solutions);
	return 0;
}

int SolutionImpossible(int x, int y)
{
 // Если произведение сторон доски нечетно и сумма координат начальной позиции
 // нечетна, то решения не существует.
    return ((N*M) % 2 != 0) && ((x+y) % 2 != 0) ;
}

int SearchSolution(int n, int x, int y)
{
	//заполняем начальную клетку
	board[x][y] = n++;

	//условие выхода из рекурсии
    if (n > N*M)
    {
		Print(N, M, board);
		solutions++;
		return 0;
	}

	for (int i = 0; i < 8; i++)
	{
		int next_x = x + possible_moves[i][0];
		int next_y = y + possible_moves[i][1];

		if (MoveAllowed(next_x, next_y))
        {
            //рекурсивно идём на сдел. шаг
            SearchSolution(n, next_x, next_y);
            // Если мы дошли до этой строки, данное частичное решение
            // не приводит к полному.
            board[next_x][next_y] =0;
        }
	}
	return 0;
}

//проверка возможности след. шага
int MoveAllowed(int x, int y)
{
        return x >= 0 && y >= 0 && x < N && y < M && board[x][y] == 0;
}

//выводим доску(и) на экран
void Print(int n, int m, int a[N][M])
{
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			printf("%4d", a[i][j]);
		printf("\n");
	}
}

//Очищаем доску
void Zero(int n, int m, int a[N][M])
{
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			a[i][j] = 0;
}
