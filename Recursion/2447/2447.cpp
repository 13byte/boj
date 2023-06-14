#include <bits/stdc++.h>
using namespace std;

void divide(int i, int j, int N)
{
	if ((i / N) % 3 == 1 && (j / N) % 3 == 1)
		cout << ' ';
	else if (N / 3 == 0)
		cout << '*';
	else
		divide(i, j, N / 3);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			divide(i, j, N);
		}
		cout << '\n';
	}
	return (0);
}