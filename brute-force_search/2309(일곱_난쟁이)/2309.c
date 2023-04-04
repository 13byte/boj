#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n)
{
	int i, j, min_idx;
	for (i = 0; i < n - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min_idx])
			{
				min_idx = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = temp;
	}
}

int main(void)
{
	int dwarf[9];
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &dwarf[i]);
		sum += dwarf[i];
	}
	selectionSort(dwarf, 9);
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			if (sum - dwarf[i] - dwarf[j] == 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j)
						continue;
					else
						printf("%d\n", dwarf[k]);
				}
				return (0);
			}
		}
	}
	return (0);
}