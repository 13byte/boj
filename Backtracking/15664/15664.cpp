#include <bits/stdc++.h>
using namespace std;

int N, M;
int dfs_arr[10];
int arr[10];

void dfs(int cur, int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; ++i)
			cout << dfs_arr[i] << ' ';
		cout << '\n';
		return;
	}
	int used = 0;
	for (int i = cur; i < N; ++i)
	{
		if (used != arr[i])
		{
			dfs_arr[len] = arr[i];
			used = dfs_arr[len];
			dfs(i + 1, len + 1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	dfs(0, 0);
	return (0);
}