#include <stdio.h>

int dp[1000001];

int ft_min(int a, int b)
{
	return ((a < b) ? a : b);
}

int main(void)
{
	int n;

	scanf("%d\n", &n);
	dp[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = ft_min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = ft_min(dp[i], dp[i / 3] + 1);
	}
	printf("%d\n", dp[n]);
	return (0);
}