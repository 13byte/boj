#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int f, s, g, u, d;
int dist[1000005];

void bfs(void)
{
	dist[s] = 0;
	q.push(s);
	while (!(q.empty()))
	{
		int cur = q.front();
		q.pop();
		for (auto nxt : {cur + u, cur - d})
		{
			if (nxt > f || nxt <= 0 || dist[nxt] != -1)
				continue;
			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> f >> s >> g >> u >> d;
	fill(dist + 1, dist + (f + 1), -1);
	bfs();

	if (dist[g] == -1)
		cout << "use the stairs\n";
	else
		cout << dist[g] << '\n';
	return (0);
}