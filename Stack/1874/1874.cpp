#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	stack<int> s;
	int cnt = 1;
	string ans;

	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		while (cnt <= t)
		{
			s.push(cnt++);
			ans += "+\n";
		}
		if (s.top() != t)
		{
			cout << "NO\n";
			return (0);
		}
		s.pop();
		ans += "-\n";
	}
	cout << ans;
	return (0);
}