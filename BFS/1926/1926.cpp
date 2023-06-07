#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[502][502];
int vis[502][502];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	int cnt = 0;
	int mx = 0;

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> board[i][j];
	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < m; ++y)
		{
			if (board[x][y] == 0 || vis[x][y])
				continue;
			queue<pair<int, int>> q;

			cnt++;
			vis[x][y] = 1;
			q.push({x, y});
			int area = 0;
			while (!q.empty())
			{
				area++;
				pair<int, int> plate = q.front();
				q.pop();
				for (int i = 0; i < 4; ++i)
				{
					int nx = plate.X + dx[i];
					int ny = plate.Y + dy[i];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (vis[nx][ny] || board[nx][ny] != 1)
						continue;
					vis[nx][ny] = 1;
					q.push({nx, ny});
				}
			}
			mx = max(mx, area);
		}
	}
	cout << cnt << '\n'
		 << mx << '\n';
	return (0);
}