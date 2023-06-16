#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<int> s;
	int n;
	ll ans;

	cin >> n;
	ll h;
	while (n--)
	{
		cin >> h;
		while (!s.empty() && s.top() <= h)
			s.pop();
		ans += s.size();
		s.push(h);
	}
	cout << ans;
	return (0);
}