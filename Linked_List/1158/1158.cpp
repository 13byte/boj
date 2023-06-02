#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, k;

	cin >> n >> k;
	list<int> lt;
	for (int i = 1; i <= n; ++i)
		lt.push_back(i);
	list<int>::iterator iter = lt.begin();
	cout << '<';
	while (!(lt.empty()))
	{
		for (int i = 0; i < k; ++i)
		{
			if (iter == lt.end())
				iter = lt.begin();
			iter++;
		}
		iter--;
		cout << *iter;
		if (lt.size() != 1)
			cout << ", ";
		iter = lt.erase(iter);
	}
	cout << '>';
	return (0);
}