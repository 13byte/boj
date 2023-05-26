#include <stdio.h>

// D[i] = i번째 계단까지 올라섰을 때 밟지 않을 계단의 합의 최솟값,
// 단 i번째 계단은 반드시 밟지 않을 계단으로 선택해야 함

// D[k] = min(D[k-2], D[k-3]) + S(K)

int D[301];
int S[301];

int min(int a, int b)
{
	return ((a < b) ? a : b);
}

int main(void)
{
	int n;
	int result = 0;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &S[i]);
		result += S[i];
	}
	if (n <= 2)
	{
		printf("%d\n", result);
		return (0);
	}
	D[1] = S[1];
	D[2] = S[2];
	D[3] = S[3];

	for (int i = 4; i < n; ++i)
		D[i] = min(D[i - 2], D[i - 3]) + S[i];
	printf("%d\n", result - min(D[n - 1], D[n - 2]));
	return (0);
}