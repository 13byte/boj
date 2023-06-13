#include <bits/stdc++.h>
using namespace std;

void recv(int a, int b, int n)
{
	if (n == 1)
	{
		cout << a << ' ' << b << '\n';
		return;
	}
	recv(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	recv(6 - a - b, b, n - 1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	cout << (1 << N) - 1 << '\n';
	recv(1, 3, N);
	return (0);
}