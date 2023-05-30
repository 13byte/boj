#include <stdio.h>

int main(void)
{
	int N;
	int result = 0;

	scanf("%d", &N);
	for (int i = 1; i <= N; i *= 10)
		result += N - i + 1;
	printf("%d\n", result);
	return (0);
}