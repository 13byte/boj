#include <bits/stdc++.h>
using namespace std;

queue<tuple<int, int, int>> q;
int board[105][105][105]; // h n m
int bfs_arr[105][105][105];
int N, M, H;

int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

void bfs(void)
{
	while (!(q.empty()))
	{
		tuple<int, int, int> cursor = q.front();
		q.pop();

		for (int dir = 0; dir < 6; ++dir)
		{
			int nz = get<0>(cursor) + dz[dir];
			int nx = get<1>(cursor) + dx[dir];
			int ny = get<2>(cursor) + dy[dir];

			if (nz < 0 || nz >= H || nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (bfs_arr[nz][nx][ny] > 0 || board[nz][nx][ny] == -1)
				continue;
			bfs_arr[nz][nx][ny] = bfs_arr[get<0>(cursor)][get<1>(cursor)][get<2>(cursor)] + 1;
			q.push({nz, nx, ny});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N >> H;
	for (int k = 0; k < H; ++k)
		for (int i = 0; i < N; ++i)
			fill(bfs_arr[k][i], bfs_arr[k][i] + M, -1);
	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				cin >> board[k][i][j];

				if (board[k][i][j] == 1)
				{
					q.push({k, i, j});
					bfs_arr[k][i][j] = 1;
				}
			}
		}
	}
	bfs();
	int mx = 0;
	for (int k = 0; k < H; ++k)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (bfs_arr[k][i][j] == -1 && board[k][i][j] != -1)
				{
					cout << -1;
					return (0);
				}
				else
				{
					mx = max(mx, bfs_arr[k][i][j]);
				}
			}
		}
	}
	cout << mx - 1;
	return (0);
}