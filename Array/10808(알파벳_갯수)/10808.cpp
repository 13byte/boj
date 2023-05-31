#include <bits/stdc++.h>
using namespace std;

int alpha_cnt[26];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;

	cin >> s;
	for (auto c : s)
		alpha_cnt[c - 'a']++;
	for (int i = 0; i < 26; ++i)
		cout << alpha_cnt[i] << ' ';
	return (0);
}