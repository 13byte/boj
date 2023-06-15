#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
bool isused[10];

void dfs(int cur, int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = cur; i <= N; ++i)
	{
		if (!(isused[i]))
		{
			arr[len] = i;
			isused[i] = true;
			dfs(i + 1, len + 1);
			isused[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	dfs(1, 0);
	return (0);
}