#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

queue<pair<int, int>> q;
int dist[305][305];
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int I, goal_x, goal_y, night_x, night_y;

void bfs(void)
{
	q.push({night_x, night_y});
	dist[night_x][night_y] = 0;

	while (!(q.empty()))
	{
		pair<int, int> cursor = q.front();
		q.pop();

		for (int dir = 0; dir < 8; ++dir)
		{
			int nx = cursor.X + dx[dir];
			int ny = cursor.Y + dy[dir];

			if (nx < 0 || nx >= I || ny < 0 || ny >= I)
				continue;
			if (dist[nx][ny] != -1)
				continue;
			dist[nx][ny] = dist[cursor.X][cursor.Y] + 1;
			q.push({nx, ny});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;
	while (t--)
	{
		cin >> I;
		for (int i = 0; i < I; ++i)
			fill(dist[i], dist[i] + I, -1);
		cin >> night_x >> night_y;
		cin >> goal_x >> goal_y;
		bfs();
		cout << dist[goal_x][goal_y] << '\n';
	}
	return (0);
}