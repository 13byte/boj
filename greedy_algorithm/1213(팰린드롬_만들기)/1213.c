#include <stdio.h>
#include <string.h>

int main(void)
{
	char name[51];
	int freq[26] = {0};
	scanf("%s", name);

	int length = strlen(name);

	for (int i = 0; i < length; i++)
		freq[name[i] - 'A']++;

	int odd_count = 0, odd_char = -1;
	int left_index = 0, right_index = length - 1;

	for (int i = 0; i < 26; i++)
	{
		if (freq[i] % 2 == 1)
		{
			odd_count++;
			odd_char = i;
		}

		while (freq[i] > 1)
		{
			name[left_index++] = 'A' + i;
			name[right_index--] = 'A' + i;
			freq[i] -= 2;
		}
	}

	if (odd_count > 1 || (odd_count == 1 && length % 2 == 0))
	{
		printf("I'm Sorry Hansoo\n");
		return (0);
	}

	if (odd_char != -1)
		name[length / 2] = 'A' + odd_char;

	name[length] = '\0';
	printf("%s\n", name);

	return (0);
}