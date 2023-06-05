#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	int k, n;
	int ans = 0;

	cin >> k;
	while (k--)
	{
		cin >> n;
		if (n == 0)
			s.pop();
		else
			s.push(n);
	}
	while (!s.empty())
	{
		ans += s.top();
		s.pop();
	}
	cout << ans;
	return (0);
}