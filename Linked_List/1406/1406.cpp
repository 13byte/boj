#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	list<char> lt;
	string n;
	char c;
	int m;

	cin >> n;
	for (auto c : n)
		lt.push_back(c);
	auto cursor = lt.end();
	cin >> m;
	while (m--)
	{
		cin >> c;
		switch (c)
		{
		case 'L':
			if (cursor != lt.begin())
				cursor--;
			break;
		case 'D':
			if (cursor != lt.end())
				cursor++;
			break;
		case 'B':
			if (cursor != lt.begin())
			{
				cursor--;
				cursor = lt.erase(cursor);
			}
			break;
		case 'P':
			cin >> c;
			lt.insert(cursor, c);
			break;
		}
	}
	for (auto c : lt)
		cout << c;
	return (0);
}