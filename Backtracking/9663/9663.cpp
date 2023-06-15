#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int board[20];

bool promising(int row)
{
	for (int col = 0; col < row; ++col)
		if (board[row] == board[col] || row - col == abs(board[row] - board[col]))
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