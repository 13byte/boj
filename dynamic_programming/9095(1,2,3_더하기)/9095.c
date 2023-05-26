#include <stdio.h>

int d[12];

int main(void)
{
	int t, n;

	d[1] = 1; // 1
	d[2] = 2; // 1 + 1, 2
	d[3] = 4; // 1 + 1 + 1, 1 + 2, 2 + 1, 3
	for (int i = 4; i < 11; ++i)
		d[i] = d[i - 1] + d[i - 2] + d[i - 3];
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		printf("%d\n", d[n]);
	}
	return (0);
}