#include <stdio.h>
#include <stdbool.h>

bool isValid(int n)
{
	int a = n / 100;
	int b = (n / 10) % 10;
	int c = n % 10;

	return (a != b && a != c && b != c && a != 0 && b != 0 && c != 0);
}

int strikeAndBall(int i_arr[3], int n_arr[3], int s, int b)
{
	int strike = 0, ball = 0;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i_arr[i] == n_arr[j])
			{
				if (i == j)
					strike++;
				else
					ball++;
			}
		}
	}

	return (strike == s && ball == b);
}

int main()
{
	int N, ans = 0;
	scanf("%d", &N);

	int cases[N][3];
	for (int i = 0; i < N; i++)
		scanf("%d %d %d", &cases[i][0], &cases[i][1], &cases[i][2]);

	for (int i = 123; i <= 987; i++)
	{
		if (!isValid(i))
			continue;

		int i_arr[3] = {i / 100, (i / 10) % 10, i % 10};
		bool isPossible = true;

		for (int j = 0; j < N && isPossible; j++)
		{
			int n_arr[3] = {cases[j][0] / 100, (cases[j][0] / 10) % 10, cases[j][0] % 10};
			isPossible = strikeAndBall(i_arr, n_arr, cases[j][1], cases[j][2]);
		}

		if (isPossible)
			ans++;
	}

	printf("%d\n", ans);
	return (0);
}