#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node
{
	int data;
	struct s_node *next;
} t_node;

typedef struct s_queue
{
	t_node *front;
	t_node *rear;
	int size;
} t_queue;

t_queue *create_queue(void);
void destroy_queue(t_queue *queue);
bool push_queue(t_queue *queue, int new_data);
bool pop_queue(t_queue *queue, int *data);
bool is_empty(const t_queue *queue);
int queue_size(const t_queue *queue);

int main(void)
{
	t_queue *queue = create_queue();
	int N;
	int data;

	scanf("%d", &N);
	if (N == 1)
	{
		printf("%d\n", 1);
		destroy_queue(queue);
		return (0);
	}
	for (int i = 1; i <= N; ++i)
		push_queue(queue, i);
	while (queue_size(queue) >= 2)
	{
		pop_queue(queue, &data);
		pop_queue(queue, &data);
		push_queue(queue, data);
	}
	printf("%d\n", data);
	destroy_queue(queue);
	return (0);
}

t_queue *create_queue(void)
{
	t_queue *new_queue = (t_queue *)malloc(sizeof(t_queue));

	if (!new_queue)
		return (NULL);
	*new_queue = (t_queue){NULL, NULL, 0};
	return (new_queue);
}

void destroy_queue(t_queue *queue)
{
	int data;

	if (!queue)
		return;
	while (pop_queue(queue, &data))
		;
	free(queue);
}

bool push_queue(t_queue *queue, const int new_data)
{
	if (!queue)
		return (false);

	t_node *new_node = (t_node *)malloc(sizeof(t_node));

	if (!new_node)
		return (false);
	new_node->data = new_data;
	new_node->next = NULL;
	if (is_empty(queue))
		queue->front = new_node;
	else
		queue->rear->next = new_node;
	queue->rear = new_node;
	queue->size++;
	return (true);
}

bool pop_queue(t_queue *queue, int *data)
{

	if (!queue || is_empty(queue) || !data)
		return (false);

	t_node *front = queue->front;

	*data = front->data;
	queue->front = front->next;
	queue->size--;
	if (!queue->front)
		queue->rear = NULL;
	free(front);
	return (true);
}

bool is_empty(const t_queue *queue)
{
	return (!queue || !queue->front);
}

int queue_size(const t_queue *queue)
{
	return (queue ? queue->size : -1);
}