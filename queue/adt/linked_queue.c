// char
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
bool push_queue(t_queue *queue, const char *new_data);
bool pop_queue(t_queue *queue, char **data);
bool is_empty(const t_queue *queue);
int queue_size(const t_queue *queue);

t_queue *create_queue(void)
{
    t_queue *new_queue = (t_queue *)malloc(sizeof(t_queue));

    if (!new_queue)
        return (NULL);
    *new_queue = (t_queue){NULL, NULL, 0};
    return (new_queue);
}

static t_node *create_node(const char *data)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));

    if (!new_node || !data || !(new_node->data = strdup(data)))
    {
        free(new_node);
        return (NULL);
    }
    new_node->next = NULL;
    return (new_node);
}

void destroy_queue(t_queue *queue)
{
    if (!queue)
        return;

    char *data;
    while (pop_queue(queue, &data))
        free(data);
    free(queue);
}

bool push_queue(t_queue *queue, const char *new_data)
{
    t_node *new_node = create_node(new_data);
    if (!queue || !new_data || !new_node)
        return (false);

    if (is_empty(queue))
        queue->front = new_node;
    else
        queue->rear->next = new_node;

    queue->rear = new_node;
    queue->size++;
    return (true);
}

bool pop_queue(t_queue *queue, char **data)
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
bool push_queue(t_queue *queue, int new_data);
bool pop_queue(t_queue *queue, int *data);
bool is_empty(const t_queue *queue);
int queue_size(const t_queue *queue);

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
    while (pop_queue(queue, &data))
        ;
    free(queue);
}

bool push_queue(t_queue *queue, int new_data)
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