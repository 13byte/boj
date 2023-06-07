#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		stack<char> s;
		string str;
		bool check = true;

		getline(cin, str);
		if (str == ".")
			break;
		for (auto c : str)
		{
			if (c == '(' || c == '[')
				s.push(c);
			else if (c == ')')
			{
				if (!(s.empty()) && s.top() == '(')
					s.pop();
				else
				{
					check = false;
					break;
				}
			}
			else if (c == ']')
			{
				if (!(s.empty()) && s.top() == '[')
					s.pop();
				else
				{
					check = false;
					break;
				}
			}
		}
		if (check && s.empty())
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
