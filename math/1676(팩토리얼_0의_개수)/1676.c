#include <stdio.h>

int solution(int n, int k)
{
	int cnt = 0;
	while (n > 1)
	{
		n /= k;
		cnt += n;
	}
	return (cnt);
}

int main(void)
{
	int N, M;
	scanf("%d %d", &N, &M);

	int five = solution(N, 5) - solution(M, 5) - solution(N - M, 5);
	int two = solution(N, 2) - solution(M, 2) - solution(N - M, 2);

	printf("%d\n", five < two ? five : two);

	return (0);
}