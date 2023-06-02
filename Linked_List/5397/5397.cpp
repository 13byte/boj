#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		string s;
		list<char> lt = {};
		list<char>::iterator iter = lt.begin();

		cin >> s;
		for (auto c : s)
		{
			switch (c)
			{
			case '<':
				if (iter != lt.begin())
					iter--;
				break;
			case '>':
				if (iter != lt.end())
					iter++;
				break;
			case '-':
				if (iter != lt.begin())
				{
					iter--;
					iter = lt.erase(iter);
				}
				break;
			default:
				lt.insert(iter, c);
				break;
			}
		}
		for (auto c : lt)
			cout << c;
		cout << '\n';
	}
	return (0);
}