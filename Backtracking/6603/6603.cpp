#include <bits/stdc++.h>
using namespace std;

int N, M = 6;
int arr[20];
int dfs_arr[20];

void dfs(int cur, int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; ++i)
			cout << dfs_arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = cur; i < N; ++i)
	{
		dfs_arr[len] = arr[i];
		dfs(i + 1, len + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		cin >> N;
		if (N == 0)
			break;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		sort(arr, arr + N);
		dfs(0, 0);
		cout << '\n';
	}
	return (0);
}