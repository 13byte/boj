#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

queue<pair<int, int>> q;
vector<int> v;
int board[105][105];
int paper[105][105];
int M, N, K;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j)
{
	int area = 0;
	q.push({i, j});
	paper[i][j] = 1;

	while (!(q.empty()))
	{
		area++;
		pair<int, int> cursor = q.front();
		q.pop();

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cursor.X + dx[dir];
			int ny = cursor.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M)
				continue;
			if (board[nx][ny] || paper[nx][ny])
				continue;
			paper[nx][ny] = 1;
			q.push({nx, ny});
		}
	}
	v.push_back(area);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt = 0;

	cin >> M >> N >> K;

	while (K--)
	{
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; ++x)
			for (int y = y1; y < y2; ++y)
				board[x][y] = 1;
	}
	for (int x = 0; x < N; ++x)
	{
		for (int y = 0; y < M; ++y)
		{
			if (board[x][y] == 0 && paper[x][y] == 0)
			{
				bfs(x, y);
				cnt++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (auto n : v)
		cout << n << ' ';
	cout << '\n';
	return (0);
}