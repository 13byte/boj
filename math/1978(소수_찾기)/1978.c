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
	int n, tmp;
	int result = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &tmp);
		if (is_prime(tmp))
			result++;
	}
	printf("%d\n", result);
	return (0);
}