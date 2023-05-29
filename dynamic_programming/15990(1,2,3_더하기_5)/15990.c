#include <stdio.h>

unsigned long long DP[100001][4];
const int mod = 1000000009;

int main(void)
{
	int T;

	scanf("%d", &T);
	DP[1][1] = DP[2][2] = DP[3][1] = DP[3][2] = DP[3][3] = 1;
	for (int i = 4; i <= 100000; ++i)
	{
		DP[i][1] = (DP[i - 1][2] + DP[i - 1][3]) % mod;
		DP[i][2] = (DP[i - 2][1] + DP[i - 2][3]) % mod;
		DP[i][3] = (DP[i - 3][1] + DP[i - 3][2]) % mod;
	}
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", (DP[n][1] + DP[n][2] + DP[n][3]) % mod);
	}
	return (0);
}