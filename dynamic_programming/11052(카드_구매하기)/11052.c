#include <stdio.h>

int dp[1001];
int P[1001];

int compare(int a, int b)
{
	return ((a < b) ? a : b);
}

int main(void)
{
	int N;

	scanf("%d", &N);
	for (int i = 1; i <= N; ++i)
		scanf("%d", &P[i]);
	dp[1] = P[1];
	for (int i = 2; i <= N; ++i)
	{
		dp[i] = P[i];
		for (int j = 1; j <= i; ++j)
		{
			dp[i] = compare(dp[i], dp[i - j] + P[j]);
		}
	}
	printf("%d\n", dp[N]);
	return (0);
}