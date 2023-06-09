#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[1005][1005];
int ripe[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;
	int m, n;

	cin >> m >> n;
	for (int i = 0; i < n; ++i)
		fill(ripe[i], ripe[i] + m, -1);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 1)
			{
				q.push({i, j});
				ripe[i][j] = 1;
			}
		}
	}
	while (!(q.empty()))
	{
		pair<int, int> cursor = q.front();
		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = cursor.X + dx[i];
			int ny = cursor.Y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (ripe[nx][ny] > 0 || board[nx][ny] == -1)
				continue;
			ripe[nx][ny] = ripe[cursor.X][cursor.Y] + 1;
			q.push({nx, ny});
		}
	}
	int mx = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; j++)
		{
			if (ripe[i][j] == -1 && board[i][j] != -1)
			{
				cout << -1;
				return (0);
			}
			else
			{
				mx = max(mx, ripe[i][j]);
			}
		}
	}
	cout << mx - 1;
	return (0);
}