#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

queue<pair<int, int>> q;
vector<int> v;
string board[30];
int bfs_arr[30][30];
int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void bfs(int i, int j)
{
	bfs_arr[i][j] = 1;
	q.push({i, j});

	int area = 0;
	while (!(q.empty()))
	{
		pair<int, int> cursor = q.front();
		q.pop();
		area++;

		for (int dir = 0; dir < 4; ++dir)
		{
			int nx = cursor.X + dx[dir];
			int ny = cursor.Y + dy[dir];

			if (nx < 0 || nx >= N || ny < 0 || ny >= N)
				continue;
			if (board[nx][ny] == '0' || bfs_arr[nx][ny] == 1)
				continue;
			bfs_arr[nx][ny] = 1;
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

	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> board[i];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == '1' && bfs_arr[i][j] == 0)
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	sort(v.begin(), v.end());
	cout << cnt << '\n';
	for (auto i : v)
		cout << i << '\n';
	return (0);
}