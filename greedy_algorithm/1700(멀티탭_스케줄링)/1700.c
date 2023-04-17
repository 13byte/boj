#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	int n, k, result = 0;
	int devices[100], multitap[100] = {
						  0,
					  };

	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &devices[i]);
	for (int i = 0; i < k; i++)
	{
		bool is_plugged = false;

		for (int j = 0; j < n; j++)
		{
			if (multitap[j] == devices[i])
			{
				is_plugged = true;
				break;
			}
		}

		if (is_plugged)
			continue;

		for (int j = 0; j < n; j++)
		{
			if (multitap[j] == 0)
			{
				multitap[j] = devices[i];
				is_plugged = true;
				break;
			}
		}

		if (!is_plugged)
		{
			int idx = 0, max_future_usage = -1;
			for (int j = 0; j < n; j++)
			{
				int future_usage;
				for (future_usage = i + 1; future_usage < k; future_usage++)
					if (multitap[j] == devices[future_usage])
						break;
				if (future_usage > max_future_usage)
				{
					idx = j;
					max_future_usage = future_usage;
				}
			}
			multitap[idx] = devices[i];
			result++;
		}
	}
	printf("%d\n", result);
	return (0);
}