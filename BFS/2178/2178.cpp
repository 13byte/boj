#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

string board[102];
int dist[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    for (int i = 0; i < n; ++i)
        fill(dist[i], dist[i] + m, -1);
    queue<pair<int, int>> q;
    dist[0][0] = 1;
    q.push({0, 0});
    while (!(q.empty()))
    {
        pair<int, int> cursor = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            int nx = cursor.X + dx[i];
            int ny = cursor.Y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (dist[nx][ny] >= 0 || board[nx][ny] != '1')
                continue;
            dist[nx][ny] = dist[cursor.X][cursor.Y] + 1;
            q.push({nx, ny});
        }
    }
    cout << dist[n - 1][m - 1];
    return (0);
}
