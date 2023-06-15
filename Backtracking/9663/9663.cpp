#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int board[20];

bool promising(int cur_row)
{
	for (int prev_row = 0; prev_row < cur_row; ++prev_row)
		if (board[cur_row] == board[prev_row] || cur_row - prev_row == abs(board[cur_row] - board[prev_row]))
			return (false);
	return (true);
}

void dfs(int row)
{
	if (row == N)
	{
		cnt++;
		return;
	}
	for (int col = 0; col < N; ++col)
	{
		board[row] = col;
		if (promising(row))
			dfs(row + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	dfs(0);
	cout << cnt;
	return (0);
}