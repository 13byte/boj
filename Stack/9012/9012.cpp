#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;

	cin >> t;
	while (t--)
	{
		stack<char> s;
		string str;
		bool error = true;

		cin >> str;
		for (char c : str)
		{
			if (c == '(')
				s.push(c);
			else
			{
				if (!(s.empty()) && s.top() == '(')
					s.pop();
				else
				{
					error = false;
					break;
				}
			}
		}
		if (error && s.empty())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return (0);
}