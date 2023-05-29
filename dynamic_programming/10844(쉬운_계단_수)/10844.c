#include <stdio.h>

unsigned long long dp[101][10];
const int mod = 1000000000;

int main(void)
{
	int n;
	unsigned long long sum = 0;

	scanf("%d", &n);
	for (int i = 1; i <= 9; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			if (j == 0)
				dp[i][j] = (dp[i - 1][1]) % mod;
			else if (j == 9)
				dp[i][j] = (dp[i - 1][8]) % mod;
			else
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
		}
	}
	for (int i = 0; i < 10; ++i)
		sum = (sum + dp[n][i]) % mod;
	printf("%lld\n", sum);
	return (0);
}