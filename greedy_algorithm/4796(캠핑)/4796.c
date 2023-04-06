#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

int main(void)
{
	int L = 1, P = 1, V = 1;

	for (int i = 1;; i++)
	{
		int cnt = 0;
		scanf("%d %d %d", &L, &P, &V);
		if (L == 0 && P == 0 && V == 0)
			break;

		cnt += (V / P) * L;				  // Add L for every full period P
		cnt += (V % P) < L ? (V % P) : L; // Add remaining days for the last period

		printf("Case %d: %d\n", i, cnt);
	}
	return (0);
}