#include <stdio.h>
#include <stdlib.h>

typedef struct s_meeting
{
	int start;
	int end;
} t_meeting;

int compare(const void *a, const void *b)
{
	t_meeting *m1 = (t_meeting *)a;
	t_meeting *m2 = (t_meeting *)b;

	if (m1->end == m2->end)
		return (m1->start - m2->start);
	return (m1->end - m2->end);
}

int main()
{
	int N;
	int count = 0;
	int last_end = 0;
	t_meeting *meetings;

	scanf("%d", &N);
	meetings = (t_meeting *)malloc(sizeof(t_meeting) * N);
	for (int i = 0; i < N; ++i)
		scanf("%d %d", &meetings[i].start, &meetings[i].end);
	qsort(meetings, N, sizeof(t_meeting), compare);
	for (int i = 0; i < N; ++i)
	{
		if (meetings[i].start >= last_end)
		{
			count++;
			last_end = meetings[i].end;
		}
	}
	printf("%d\n", count);
	return (0);
}