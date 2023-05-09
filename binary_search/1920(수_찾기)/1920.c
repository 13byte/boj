#include <stdio.h>
#include <stdlib.h>

int binary_search(const int arr[], const int arr_size, const int target_value)
{
    int left_bound = 0;
    int right_bound = arr_size - 1;

    while (left_bound <= right_bound)
    {
        int middle_index = left_bound + ((right_bound - left_bound) / 2);
        int value_at_middle = arr[middle_index];

        if (target_value == value_at_middle)
            return (1);
        else if (target_value < value_at_middle)
            right_bound = middle_index - 1;
        else if (target_value > value_at_middle)
            left_bound = middle_index + 1;
    }
    return (0);
}

int compare_ints(const void *first, const void *second)
{
    int a = *(const int *)first;
    int b = *(const int *)second;
    return ((a > b) - (a < b));
}

int main(void)
{
    int N, M;
    int tmp;

    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);

    qsort(arr, N, sizeof(int), compare_ints);

    scanf("%d", &M);
    for (int i = 0; i < M; ++i)
    {
        scanf("%d", &tmp);
        printf("%d\n", binary_search(arr, N, tmp));
    }
    return (0);
}