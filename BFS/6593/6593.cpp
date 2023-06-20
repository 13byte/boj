#include <bits/stdc++.h>
using namespace std;

queue<tuple<int, int, int>> q;
string board[35][35];
int bfs_arr[35][35][35];
int L, R, C;
int dx[] = {1, 0, -1, 0, 0, 0};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

void bfs(void)
{
	while (!(q.empty()))
	{
		auto cur = q.front();
		q.pop();
		int curZ, curX, curY;
		tie(curZ, curX, curY) = cur;
		for (int dir = 0; dir < 6; ++dir)
		{
			int nz = curZ + dz[dir];
			int nx = curX + dx[dir];
			int ny = curY + dy[dir];

			if (nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C)
				continue;
			if (board[nz][nx][ny] == '#' || bfs_arr[nz][nx][ny] != -1)
				continue;
			bfs_arr[nz][nx][ny] = bfs_arr[curZ][curX][curY] + 1;
			q.push({nz, nx, ny});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		for (int k = 0; k < L; ++k)
			for (int i = 0; i < R; ++i)
				cin >> board[k][i];

		for (int k = 0; k < L; ++k)
			for (int i = 0; i < R; ++i)
				fill(bfs_arr[k][i], bfs_arr[k][i] + C, -1);

		for (int k = 0; k < L; ++k)
		{
			for (int i = 0; i < R; ++i)
			{
				for (int j = 0; j < C; ++j)
				{
					if (board[k][i][j] == 'S')
					{
						q.push({k, i, j});
						bfs_arr[k][i][j] = 0;
					}
				}
			}
		}
		bfs();
		for (int k = 0; k < L; ++k)
		{
			for (int i = 0; i < R; ++i)
			{
				for (int j = 0; j < C; ++j)
				{
					if (board[k][i][j] == 'E')
					{
						if (bfs_arr[k][i][j] == -1)
							cout << "Trapped!\n";
						else
							cout << "Escaped in " << bfs_arr[k][i][j] << " minute(s).\n";
					}
				}
			}
		}
	}
	return (0);
}