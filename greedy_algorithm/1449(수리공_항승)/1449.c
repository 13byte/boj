#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

void selection_sort(int arr[], int n)
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
	int n, l;
	int cnt = 0;
	int *arr;

	scanf("%d %d", &n, &l);
	arr = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	selection_sort(arr, n);
	for (int i = 0; i < n;)
	{
		int covered_position = arr[i] + l - 1;
		cnt++;
		while (i < n && arr[i] <= covered_position)
			i++;
	}
	printf("%d\n", cnt);
	free(arr);
	return (0);
}