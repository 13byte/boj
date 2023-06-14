#include <bits/stdc++.h>
using namespace std;

int board[2190][2190];
int cnt[3]; // -1, 0, 1

bool check(int x, int y, int N)
{
	for (int i = x; i < x + N; ++i)
		for (int j = y; j < y + N; ++j)
			if (board[x][y] != board[i][j]) // 다른 수가 있는지 확인
				return (false);
	return (true);
}

void divide(int x, int y, int N)
{
	if (check(x, y, N))
	{
		cnt[board[x][y] + 1]++; // (-1, 0, 1) + 1 = (0, 1, 2);
	}
	else
	{
		int board_size = N / 3;

		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j)
				divide(x + (board_size * i), y + (board_size * j), board_size);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	for (int x = 0; x < N; ++x)
		for (int y = 0; y < N; ++y)
			cin >> board[x][y];
	divide(0, 0, N); // 시작점 0, 0
	cout << cnt[0] << '\n'
		 << cnt[1] << '\n'
		 << cnt[2] << '\n';
	return (0);
}