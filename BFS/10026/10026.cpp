#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

queue<pair<int, int>> q;
string board[105];
int vis[105][105];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N;

void bfs(int i, int j)
{
	q.push({i, j});
	vis[i][j] = 1;
	while (!(q.empty()))
	{
		pair<int, int> cursor = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cursor.X + dx[dir];
			int ny = cursor.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (board[i][j] != board[nx][ny] || vis[nx][ny])
				continue;
			vis[nx][ny] = 1;
			q.push({nx, ny});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0, rg_cnt = 0;

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> board[i];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!(vis[i][j]))
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	for (int i = 0; i < N; ++i)
		fill(vis[i], vis[i] + N, 0);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (board[i][j] == 'G')
				board[i][j] = 'R';
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (!(vis[i][j]))
			{
				bfs(i, j);
				rg_cnt++;
			}
		}
	}
	cout << cnt << ' ' << rg_cnt << '\n';
}