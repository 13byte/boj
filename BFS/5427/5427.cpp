#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[1005];
int fire[1005][1005];
int me[1005][1005];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int w, h;

void fire_bfs(queue<pair<int, int>> &fire_q)
{
	while (!(fire_q.empty()))
	{
		pair<int, int> cursor = fire_q.front();
		fire_q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cursor.X + dx[dir];
			int ny = cursor.Y + dy[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				continue;
			if (board[nx][ny] == '#' || fire[nx][ny] >= 0)
				continue;
			fire[nx][ny] = fire[cursor.X][cursor.Y] + 1;
			fire_q.push({nx, ny});
		}
	}
}

void me_bfs(queue<pair<int, int>> &me_q)
{
	while (!(me_q.empty()))
	{
		pair<int, int> cursor = me_q.front();
		me_q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cursor.X + dx[dir];
			int ny = cursor.Y + dy[dir];

			if (nx < 0 || nx >= h || ny < 0 || ny >= w)
			{
				cout << me[cursor.X][cursor.Y] << '\n';
				return;
			}
			if (board[nx][ny] == '#' || me[nx][ny] >= 0)
				continue;
			if (fire[nx][ny] != -1 && fire[nx][ny] <= me[cursor.X][cursor.Y] + 1)
				continue;
			me[nx][ny] = me[cursor.X][cursor.Y] + 1;
			me_q.push({nx, ny});
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;
	while (t--)
	{
		queue<pair<int, int>> fire_q;
		queue<pair<int, int>> me_q;

		cin >> w >> h;
		for (int i = 0; i < h; ++i)
		{
			fill(fire[i], fire[i] + w, -1);
			fill(me[i], me[i] + w, -1);
		}
		for (int i = 0; i < h; ++i)
			cin >> board[i];
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (board[i][j] == '*')
				{
					fire_q.push({i, j});
					fire[i][j] = 1;
				}
				if (board[i][j] == '@')
				{
					me_q.push({i, j});
					me[i][j] = 1;
				}
			}
		}
		fire_bfs(fire_q);
		me_bfs(me_q);
	}
	return (0);
}