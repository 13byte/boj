#include <stdio.h>

int euclidean(int a, int b)
{
	int r = a % b;

	if (r == 0)
		return (b);
	return (euclidean(b, r));
}

int main(void)
{
	int x, y, t;

	scanf("%d", &t);
	while (t--)
	{
		scanf("%d %d", &x, &y);
		printf("%d\n", (x * y) / euclidean(x, y));
	}
	return (0);
}