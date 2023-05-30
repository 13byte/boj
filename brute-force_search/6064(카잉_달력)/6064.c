#include <stdio.h>

int main(void)
{
	int t;
	int m, n, x, y;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d %d %d %d", &m, &n, &x, &y);
		x--, y--; // 0-indexed
		for (int year = x;; year += m)
		{
			if (year % n == y)
			{
				printf("%d\n", year + 1); // 1-indexed
				break;
			}
			if (year >= m * n)
			{
				printf("-1\n");
				break;
			}
		}
	}
	return 0;
}