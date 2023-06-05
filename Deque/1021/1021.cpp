#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	deque<int> dq;
	int n, m;
	int ans = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		dq.push_back(i);
	while (m--)
	{
		int t;

		cin >> t;
		int idx = find(dq.begin(), dq.end(), t) - dq.begin();
		while (dq.front() != t)
		{
			if (idx < dq.size() - idx)
			{
				dq.push_back(dq.front());
				dq.pop_front();
			}
			else
			{
				dq.push_front(dq.back());
				dq.pop_back();
			}
			ans++;
		}
		dq.pop_front();
	}
	cout << ans;
	return (0);
}