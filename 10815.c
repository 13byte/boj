#include <stdio.h>
#include <stdlib.h>

int binary_search(const int arr[], int arr_size, int target_value)
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
        else
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

void read_array(int size, int arr[])
{
    for (int i = 0; i < size; ++i)
        scanf("%d", &arr[i]);
}

int main(void)
{
    int N, M;

    scanf("%d", &N);
    int n_arr[N];
    read_array(N, n_arr);

    scanf("%d", &M);
    int m_arr[M];
    read_array(M, m_arr);

    qsort(n_arr, N, sizeof(int), compare_ints);

    for (int i = 0; i < M; ++i)
        printf("%d ", binary_search(n_arr, N, m_arr[i]));

    return (0);
}