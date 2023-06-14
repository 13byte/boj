#include <bits/stdc++.h>
using namespace std;

int n, m;
int arr[10];
bool isused[10];

void back(int select_num)
{
	if (select_num == m)
	{
		for (int i = 0; i < m; ++i)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (!isused[i])
		{
			arr[select_num] = i;
			isused[i] = true;
			back(select_num + 1);
			isused[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	back(0);
	return (0);
}