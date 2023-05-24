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
	int x, y, tmp;

	scanf("%d %d", &x, &y);
	tmp = euclidean(x, y);
	printf("%d\n", tmp);
	printf("%d\n", (x * y) / tmp);
	return (0);
}