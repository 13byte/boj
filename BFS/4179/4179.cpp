#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1005];
int fire_route[1005][1005];
int jihun_route[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> jihun_q;
	queue<pair<int, int>> fire_q;
	int x, y;

	cin >> x >> y;
	for (int i = 0; i < x; ++i)
	{
		fill(jihun_route[i], jihun_route[i] + y, -1);
		fill(fire_route[i], fire_route[i] + y, -1);
	}
	for (int i = 0; i < x; ++i)
		cin >> board[i];
	for (int i = 0; i < x; ++i)
	{
		for (int j = 0; j < y; ++j)
		{
			if (board[i][j] == 'J')
			{
				jihun_q.push({i, j});
				jihun_route[i][j] = 1;
			}
			if (board[i][j] == 'F')
			{
				fire_q.push({i, j});
				fire_route[i][j] = 1;
			}
		}
	}

	while (!(fire_q.empty()))
	{
		pair<int, int> cursor = fire_q.front();
		fire_q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cursor.X + dx[dir];
			int ny = cursor.Y + dy[dir];

			if (nx < 0 || nx >= x || ny < 0 || ny >= y)
				continue;
			if (board[nx][ny] == '#' || fire_route[nx][ny] >= 0)
				continue;
			fire_route[nx][ny] = fire_route[cursor.X][cursor.Y] + 1;
			fire_q.push({nx, ny});
		}
	}
	while (!(jihun_q.empty()))
	{
		pair<int, int> cursor = jihun_q.front();
		jihun_q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cursor.X + dx[dir];
			int ny = cursor.Y + dy[dir];

			if (nx < 0 || nx >= x || ny < 0 || ny >= y)
			{
				cout << jihun_route[cursor.X][cursor.Y];
				return (0);
			}
			if (board[nx][ny] == '#' || jihun_route[nx][ny] >= 0)
				continue;
			if (fire_route[nx][ny] != -1 && fire_route[nx][ny] <= jihun_route[cursor.X][cursor.Y] + 1)
				continue;
			jihun_route[nx][ny] = jihun_route[cursor.X][cursor.Y] + 1;
			jihun_q.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE";
	return (0);
}