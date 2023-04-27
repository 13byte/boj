#include <stdio.h>
#include <string.h>
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
bool en_queue(t_queue *queue, int new_data);
bool de_queue(t_queue *queue, int *data);
bool is_empty(const t_queue *queue);
int queue_size(const t_queue *queue);

int main(void)
{
	int N;
	int num;
	char command[6];
	t_queue *queue = create_queue();

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &num);
			en_queue(queue, num);
		}
		else if (strcmp(command, "pop") == 0)
		{
			if (de_queue(queue, &num))
				printf("%d\n", num);
			else
				printf("-1\n");
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", queue_size(queue));
		}
		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", is_empty(queue));
		}
		else if (strcmp(command, "front") == 0)
		{
			if (queue->front)
				printf("%d\n", queue->front->data);
			else
				printf("-1\n");
		}
		else if (strcmp(command, "back") == 0)
		{
			if (queue->rear)
				printf("%d\n", queue->rear->data);
			else
				printf("-1\n");
		}
	}
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
	if (!queue)
		return;

	int data;
	while (de_queue(queue, &data))
		;
	free(queue);
}

bool en_queue(t_queue *queue, int new_data)
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

bool de_queue(t_queue *queue, int *data)
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