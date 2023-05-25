#include <stdio.h>
#define MAX 1000000

int prime[MAX];
void sieve()
{
	for (int i = 2; i * i <= MAX; i++)
	{
		if (prime[i] == 0)
		{
			for (int j = i * i; j <= MAX; j += i)
			{
				prime[j] = 1;
			}
		}
	}
	for (int i = 2; i <= MAX; i++)
	{
		if (prime[i] == 0)
			prime[i] = 1;
		else
			prime[i] = 0;
	}
}

int main(void)
{
	int n;

	sieve();
	while (1)
	{
		scanf("%d", &n);
		if (n == 0)
			break;
		for (int i = 2; i <= n / 2; i++)
		{
			if (prime[i] && prime[n - i])
			{
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
	}
	return (0);
}
