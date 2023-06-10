#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[55][55];
int worm[55][55];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int m, n, k;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;
	int t;
	int m, n, k;

	cin >> t;
	while (t--)
	{
		cin >> m >> n >> k;
		for (int i = 0; i < k; ++i)
		{
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		int worm_cnt = 0;
		for (int x = 0; x < n; ++x)
		{
			for (int y = 0; y < m; ++y)
			{
				if (board[x][y] == 1 && worm[x][y] == 0)
				{
					worm[x][y] = 1;
					q.push({x, y});

					while (!(q.empty()))
					{
						pair<int, int> cursor = q.front();
						q.pop();

						for (int dir = 0; dir < 4; ++dir)
						{
							int nx = cursor.X + dx[dir];
							int ny = cursor.Y + dy[dir];

							if (nx < 0 || nx >= n || ny < 0 || ny >= m)
								continue;
							if (board[nx][ny] != 1 || worm[nx][ny])
								continue;
							worm[nx][ny] = 1;
							q.push({nx, ny});
						}
					}
					worm_cnt++;
				}
			}
		}
		for (int i = 0; i < n; ++i)
		{
			fill(board[i], board[i] + m, 0);
			fill(worm[i], worm[i] + m, 0);
		}
		cout << worm_cnt << '\n';
	}
}