#include <stdio.h>

int main()
{
	int N, K;
	int *coins;
	scanf("%d %d", &N, &K);

	coins = (int *)malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++)
		scanf("%d", &coins[i]);
	int count = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		if (K >= coins[i])
		{
			count += K / coins[i];
			K %= coins[i];
		}
	}
	printf("%d\n", count);
	return (0);
}
