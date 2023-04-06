#include <stdio.h>

int main(void)
{
	int l, p, v, i = 1;

	while (scanf("%d %d %d", &l, &p, &v), l || p || v)
		printf("Case %d: %d\n", i++, (v / p) * l + (v % p < l ? v % p : l));
	return (0);
}