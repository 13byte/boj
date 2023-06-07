#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt = 0;

	cin >> n;
	while (n--)
	{
		stack<int> s;
		string str;

		cin >> str;
		for (auto c : str)
		{
			if (!s.empty() && s.top() == c)
				s.pop();
			else
				s.push(c);
		}
		if (s.empty())
			cnt++;
	}
	cout << cnt << "\n";
}