#include <bits/stdc++.h>
using namespace std;

string board[70];

bool check(int row, int col, int N)
{
	for (int x = row; x < row + N; ++x)
		for (int y = col; y < col + N; ++y)
			if (board[row][col] != board[x][y])
				return (false);
	return (true);
}

void divide(int row, int col, int N)
{
	if (check(row, col, N))
	{
		cout << board[row][col];
	}
	else
	{
		cout << '(';
		int board_size = N / 2;

		for (int x = 0; x < 2; ++x)
			for (int y = 0; y < 2; ++y)
				divide(row + (board_size * x), col + (board_size * y), board_size);
		cout << ')';
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> board[i];
	divide(0, 0, N);
	return (0);
}