#include <stdio.h>

int memo[1000001];

int ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}

int main(void)
{
	int n;

	scanf("%d\n", &n);
	memo[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		memo[i] = memo[i - 1] + 1;
		if (i % 2 == 0)
			memo[i] = ft_min(memo[i], memo[i / 2] + 1);
		if (i % 3 == 0)
			memo[i] = ft_min(memo[i], memo[i / 3] + 1);
	}
	printf("%d\n", memo[n]);
	return (0);
}