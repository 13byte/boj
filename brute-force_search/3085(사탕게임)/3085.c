#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 50

int N;
char board[MAX_N][MAX_N + 1];

int max(int a, int b)
{
	return (a > b ? a : b);
}

int check(int x, int y)
{
	int max_count = 1;

	// Check row
	int count = 1;
	for (int i = 1; i < N; ++i)
	{
		if (board[x][i] == board[x][i - 1])
		{
			count++;
			max_count = max(max_count, count);
		}
		else
		{
			count = 1;
		}
	}
	// Check column
	count = 1;
	for (int i = 1; i < N; ++i)
	{
		if (board[i][y] == board[i - 1][y])
		{
			count++;
			max_count = max(max_count, count);
		}
		else
		{
			count = 1;
		}
	}

	return (max_count);
}

int main(void)
{
	int result = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
		scanf("%s", board[i]);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (j + 1 < N)
			{
				char temp = board[i][j];
				board[i][j] = board[i][j + 1];
				board[i][j + 1] = temp;

				result = max(result, check(i, j));
				result = max(result, check(i, j + 1));

				temp = board[i][j];
				board[i][j] = board[i][j + 1];
				board[i][j + 1] = temp;
			}
			if (i + 1 < N)
			{
				char temp = board[i][j];
				board[i][j] = board[i + 1][j];
				board[i + 1][j] = temp;

				result = max(result, check(i, j));
				result = max(result, check(i + 1, j));

				temp = board[i][j];
				board[i][j] = board[i + 1][j];
				board[i + 1][j] = temp;
			}
		}
	}
	printf("%d\n", result);
	return (0);
}