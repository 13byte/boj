#include <stdio.h>

int house[1001][4]; // 1 (Red), 2 (Green), 3 (Blue)
int r[1001], g[1001], b[1001];

int min2(int a, int b)
{
	return ((a < b) ? a : b);
}

int min3(int a, int b, int c)
{
	int min = a;

	if (min > b)
		min = b;
	if (min > c)
		min = c;
	return (min);
}

int main(void)
{
	int n;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d %d %d", &r[i], &g[i], &b[i]);
	house[1][1] = r[1];
	house[1][2] = g[1];
	house[1][3] = b[1];
	for (int i = 2; i <= n; ++i)
	{
		house[i][1] = min2(house[i - 1][2], house[i - 1][3]) + r[i];
		house[i][2] = min2(house[i - 1][1], house[i - 1][3]) + g[i];
		house[i][3] = min2(house[i - 1][1], house[i - 1][2]) + b[i];
	}
	printf("%d\n", min3(house[n][1], house[n][2], house[n][3]));
	return (0);
}