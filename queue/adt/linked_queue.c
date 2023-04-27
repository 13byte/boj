#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node
{
    char *data;
    struct s_node *next;
} t_node;

typedef struct s_queue
{
    t_node *front;
    t_node *rear;
    int size;
} t_queue;

t_queue *create_queue(void);
static t_node *create_node(const char *data);
void destroy_queue(t_queue *queue);
void en_queue(t_queue *queue, char *new_data);
bool de_queue(t_queue *queue, char **data);
bool is_empty(t_queue *queue);
int queue_size(t_queue *queue);

t_queue *create_queue(void)
{
    t_queue *new_queue = malloc(sizeof(t_queue));

    if (!new_queue)
        return (NULL);
    new_queue->front = new_queue->rear = NULL;
    new_queue->size = 0;
    return (new_queue);
}

static t_node *create_node(const char *data)
{
    t_node *new_node = malloc(sizeof(t_node));

    if (!new_node)
        return (NULL);
    new_node->data = strdup(data);
    new_node->next = NULL;
    return (new_node);
}

void destroy_queue(t_queue *queue)
{
    if (!queue)
        return;

    while (!is_empty(queue))
    {
        char *data;
        de_queue(queue, &data);
        free(data);
    }
    free(queue);
}

void en_queue(t_queue *queue, char *new_data)
{
    t_node *new_node = create_node(new_data);

    if (!queue || !new_data || !new_node)
        return;
    if (is_empty(queue))
        queue->front = new_node;
    else
        queue->rear->next = new_node;
    queue->rear = new_node;
    queue->size++;
}

bool de_queue(t_queue *queue, char **data)
{
    t_node *front = queue->front;

    if (!queue || is_empty(queue))
        return (false);
    *data = front->data;
    queue->front = front->next;
    queue->size--;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(front);
    return (true);
}

bool is_empty(t_queue *queue)
{
    return (!queue || (queue->front == NULL));
}

int queue_size(t_queue *queue)
{
    return (queue ? queue->size : -1);
}