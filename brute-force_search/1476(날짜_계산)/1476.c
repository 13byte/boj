#include <stdio.h>

int main(void)
{
	int year;
	int e, s, m; // e <= 15, s <= 28, m <= 19;
	int a = 0, b = 0, c = 0;

	scanf("%d %d %d", &e, &s, &m);
	for (int year = 1;; ++year)
	{
		a++;
		b++;
		c++;
		if (a == 16)
			a = 1;
		if (b == 29)
			b = 1;
		if (c == 20)
			c = 1;
		if (a == e && b == s && c == m)
		{
			printf("%d\n", year);
			return (0);
		}
	}
	return (0);
}