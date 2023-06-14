#include <bits/stdc++.h>
using namespace std;

int board[130][130];
int cnt[2];

bool check(int x, int y, int N)
{
	for (int row = x; row < x + N; ++row)
		for (int col = y; col < y + N; ++col)
			if (board[x][y] != board[row][col])
				return (false);
	return (true);
}

void divide(int x, int y, int N)
{
	if (check(x, y, N))
	{
		cnt[board[x][y]]++;
	}
	else
	{
		int board_size = N / 2;

		for (int row = 0; row < 2; ++row)
			for (int col = 0; col < 2; ++col)
				divide(x + (board_size * row), y + (board_size * col), board_size);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];
	divide(0, 0, N);
	cout << cnt[0] << '\n'
		 << cnt[1] << '\n';
	return (0);
}