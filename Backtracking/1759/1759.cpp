#include <bits/stdc++.h>
using namespace std;

int L, C;
char arr[20];
int dfs_arr[20];

bool aeiou(char vowel)
{
	return vowel == 'a' || vowel == 'e' || vowel == 'i' || vowel == 'o' || vowel == 'u';
}

void dfs(int cur, int len)
{
	if (len == L)
	{
		int vowels = 0;
		int consonants = 0;

		for (int i = 0; i < L; ++i)
		{
			if (aeiou(arr[dfs_arr[i]]))
				vowels++;
			else
				consonants++;
		}
		if (vowels >= 1 && consonants >= 2)
		{
			for (int i = 0; i < L; ++i)
				cout << arr[dfs_arr[i]];
			cout << "\n";
		}
	}
	for (int i = cur; i < C; ++i)
	{
		dfs_arr[len] = i;
		dfs(i + 1, len + 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; ++i)
		cin >> arr[i];
	sort(arr, arr + C);
	dfs(0, 0);
	return (0);
}