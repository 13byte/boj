#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node
{
    int data;
} t_node;

typedef struct s_queue
{
    int capacity;
    int front;
    int rear;
    t_node *nodes;
} t_queue;

t_queue *create_queue(int capacity);
void destroy_queue(t_queue *queue);
bool en_queue(t_queue *queue, int data);
bool de_queue(t_queue *queue, int *data);
int get_size(t_queue *queue);
bool is_empty(t_queue *queue);
bool is_full(t_queue *queue);

int main(void)
{
    t_queue *queue = create_queue(10);
    int data;

    for (int i = 1; i <= 5; ++i)
        en_queue(queue, i);
    for (int i = 1; i <= 3; ++i)
    {
        de_queue(queue, &data);
        printf("Dequeue : %d, Front : %d, Rear : %d\n", data, queue->front, queue->rear);
    }
    for (int i = 100; !is_full(queue); ++i)
        en_queue(queue, i);

    printf("Capacity : %d, Size : %d\n\n", queue->capacity, get_size(queue));

    while (!is_empty(queue))
    {
        de_queue(queue, &data);
        printf("Dequeue : %d, Front : %d, Rear : %d\n", data, queue->front, queue->rear);
    }
    destroy_queue(queue);
    return (0);
}

t_queue *create_queue(int capacity)
{
    t_queue *queue = (t_queue *)malloc(sizeof(t_queue));
    queue->nodes = (t_node *)malloc(sizeof(t_node) * (capacity + 1));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = 0;
    return (queue);
}

void destroy_queue(t_queue *queue)
{
    free(queue->nodes);
    free(queue);
}

bool en_queue(t_queue *queue, int data)
{
    if (is_full(queue))
        return (false);
    queue->nodes[queue->rear].data = data;
    queue->rear = (queue->rear + 1) % (queue->capacity + 1);
    return (true);
}

bool de_queue(t_queue *queue, int *data)
{
    if (is_empty(queue))
        return (false);
    *data = queue->nodes[queue->front].data;
    queue->front = (queue->front + 1) % (queue->capacity + 1);
    return (true);
}

int get_size(t_queue *queue)
{
    return (queue->rear - queue->front + queue->capacity + 1) % (queue->capacity + 1);
}

bool is_empty(t_queue *queue)
{
    return (queue->front == queue->rear);
}

bool is_full(t_queue *queue)
{
    return (((queue->rear + 1) % (queue->capacity + 1)) == queue->front);
}