#include <bits/stdc++.h>
using namespace std;

int dist[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int n, k;

	cin >> n >> k;
	fill(dist, dist + 100001, -1);
	dist[n] = 0;
	q.push(n);
	while (!(q.empty()))
	{
		int cursor = q.front();
		q.pop();

		for (int nxt : {cursor - 1, cursor + 1, 2 * cursor})
		{
			if (nxt < 0 || nxt > 100000)
				continue;
			if (dist[nxt] != -1)
				continue;
			dist[nxt] = dist[cursor] + 1;
			q.push(nxt);
		}
	}
	cout << dist[k];
}