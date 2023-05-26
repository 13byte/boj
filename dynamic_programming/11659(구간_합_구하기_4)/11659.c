#include <stdio.h>

int dp[100001];
int s[100001];

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);
	dp[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &s[i]);
		dp[i] = dp[i - 1] + s[i];
	}
	while (m--)
	{
		int i, j;
		scanf("%d %d", &i, &j);
		printf("%d\n", dp[j] - dp[i - 1]);
	}
	return (0);
}