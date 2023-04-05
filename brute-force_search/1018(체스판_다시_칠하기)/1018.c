#include <stdio.h>

int min(int a, int b)
{
	return (a < b ? a : b);
}

int count_mismatches(char board[][50], int x, int y)
{
	int mismatches = 0;

	for (int i = 0; i < 8; ++i)
		for (int j = 0; j < 8; ++j)
			mismatches += (((i + j) % 2) == (board[x + i][y + j] == 'W'));
	return (min(mismatches, 64 - mismatches));
}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);

	char board[50][50];
	for (int i = 0; i < N; i++)
		scanf("%s", board[i]);
	int min_mismatches = 64;
	for (int i = 0; i <= N - 8; i++)
		for (int j = 0; j <= M - 8; j++)
			min_mismatches = min(min_mismatches, count_mismatches(board, i, j));
	printf("%d\n", min_mismatches);
	return (0);
}