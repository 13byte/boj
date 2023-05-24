#include <stdio.h>

int is_prime(int nb)
{
	if (nb < 2)
		return (0);
	for (int i = 2; i <= nb / i; ++i)
		if (nb % i == 0)
			return (0);
	return (1);
}

int main(void)
{
	int n, m;

	scanf("%d %d", &n, &m);
	for (int i = n; i <= m; ++i)
		if (is_prime(i))
			printf("%d\n", i);
	return (0);
}