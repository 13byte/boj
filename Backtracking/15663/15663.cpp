#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[10];
int dfs_arr[10];
bool isused[10];

void dfs(int cur, int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; ++i)
			cout << arr[dfs_arr[i]] << ' ';
		cout << '\n';
		return;
	}
	int used = 0;
	for (int i = 0; i < N; ++i)
	{
		if (!isused[i] && used != arr[i])
		{
			dfs_arr[len] = i;
			used = arr[i];
			isused[i] = true;
			dfs(i, len + 1);
			isused[i] = false;
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