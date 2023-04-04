#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int N;
	int x, sum;

	scanf("%d", &N);
	for (int i = 1; i <= 1000000; ++i)
	{
		x = i;
		sum = 0;
		while (x)
		{
			sum += x % 10;
			x = x / 10;
		}
		if (i + sum == N)
		{
			printf("%d\n", i);
			return (0);
		}
	}
	printf("0\n");
	return (0);
}