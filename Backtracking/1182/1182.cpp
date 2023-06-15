#include <bits/stdc++.h>
using namespace std;

int n, s;
int arr[30];
int cnt = 0;

void dfs(int cur, int tot)
{
	if (cur == n)
	{
		if (tot == s)
			cnt++;
		return;
	}
	dfs(cur + 1, tot);
	dfs(cur + 1, tot + arr[cur]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	dfs(0, 0);
	if (s == 0)
		cnt--;
	cout << cnt;
	return (0);
}