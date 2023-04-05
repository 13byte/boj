#include <stdio.h>
#include <stdlib.h>

int check_triangular_number(int num)
{
	int a, b, c;

	for (int i = 1; i * (i + 1) / 2 <= num; ++i)
	{
		a = (i * (i + 1)) / 2;
		for (int j = 1; j * (j + 1) / 2 <= num - a; ++j)
		{
			b = (j * (j + 1)) / 2;
			for (int k = 1; k * (k + 1) / 2 <= num - a - b; ++k)
			{
				c = (k * (k + 1)) / 2;
				if (a + b + c == num)
					return (1);
			}
		}
	}

	return (0);
}

int main(void)
{
	int T;
	int num;

	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &num);
		printf("%d\n", check_triangular_number(num));
	}
	return (0);
}