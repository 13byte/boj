#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int *arr, int size, int is_descending)
{
	int tmp;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			int should_swap = is_descending ? arr[i] < arr[j] : arr[i] > arr[j];
			if (should_swap)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}

int main(void)
{
	int N, K;
	int *arr1, *arr2;
	int tmp, result = 0;

	scanf("%d", &N);
	scanf("%d", &K);
	arr1 = (int *)malloc(sizeof(int) * N);
	arr2 = (int *)malloc(sizeof(int) * (N - 1));

	for (int i = 0; i < N; ++i)
		scanf("%d", arr1 + i);
	bubble_sort(arr1, N, 0); // Sort in ascending order

	for (int i = 0; i < N - 1; ++i)
		arr2[i] = arr1[i + 1] - arr1[i];
	bubble_sort(arr2, N - 1, 1); // Sort in descending order

	for (int i = K - 1; i < N - 1; ++i)
		result += arr2[i];
	printf("%d\n", result);
	free(arr1);
	free(arr2);
	return 0;
}