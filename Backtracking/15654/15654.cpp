#include <bits/stdc++.h>
using namespace std;

int N, M;
int dfs_arr[10];
int arr[10];
bool isused[10005];

void dfs(int cur, int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; ++i)
			cout << dfs_arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		if (!(isused[arr[i]]))
		{
			dfs_arr[len] = arr[i];
			isused[arr[i]] = true;
			dfs(i, len + 1);
			isused[arr[i]] = false;
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