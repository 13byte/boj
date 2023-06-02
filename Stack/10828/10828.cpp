#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	stack<int> stk;

	int n;
	cin >> n;
	while (n--)
	{
		string s;
		cin >> s;
		if (s == "push")
		{
			int num;
			cin >> num;
			stk.push(num);
		}
		else if (s == "pop")
		{
			if (stk.empty())
				cout << -1 << '\n';
			else
			{
				cout << stk.top() << '\n';
				stk.pop();
			}
		}
		else if (s == "size")
		{
			cout << stk.size() << '\n';
		}
		else if (s == "empty")
		{
			cout << stk.empty() << '\n';
		}
		else if (s == "top")
		{
			if (stk.empty())
				cout << -1 << '\n';
			else
				cout << stk.top() << '\n';
		}
	}
	return (0);
}