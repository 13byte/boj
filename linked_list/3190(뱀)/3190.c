#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

typedef struct s_node
{
	int x;
	int y;
	struct s_node *prev;
	struct s_node *next;
} t_node;

t_node node[10001];
int node_cnt = 0;

void append_node(t_node **head, int x, int y)
{
	t_node *new_node = &node[node_cnt++];
	new_node->x = x;
	new_node->y = y;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
}

bool move_snake(t_node **head, int dx, int dy, int **matrix, int N)
{
	int new_x = (*head)->x + dx;
	int new_y = (*head)->y + dy;

	if (new_x < 0 || new_x >= N || new_y < 0 || new_y >= N)
		return false;

	t_node *temp = *head;
	while (temp->next != NULL)
	{
		if (temp->x == new_x && temp->y == new_y)
			return false;
		temp = temp->next;
	}

	if (temp->x == new_x && temp->y == new_y)
		return false;

	if (matrix[new_x][new_y] == 2)
	{
		matrix[new_x][new_y] = 0;
		append_node(head, new_x, new_y);
	}
	else
	{
		t_node *tail = temp;
		t_node *new_head = &node[node_cnt++];
		new_head->x = new_x;
		new_head->y = new_y;
		new_head->prev = NULL;
		new_head->next = *head;
		(*head)->prev = new_head;
		*head = new_head;

		if (tail->prev != NULL)
		{
			tail->prev->next = NULL;
		}
		else
		{
			matrix[tail->x][tail->y] = 0;
		}
	}
	return true;
}

int main(void)
{
	int N, K, L, time = 0;
	int **matrix;

	scanf("%d", &N);
	matrix = (int **)malloc(sizeof(int *) * N);
	for (int i = 0; i < N; i++)
	{
		matrix[i] = (int *)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
		{
			matrix[i][j] = 0;
		}
	}

	scanf("%d", &K);
	for (int i = 0; i < K; i++)
	{
		int row, column;
		scanf("%d %d", &row, &column);
		matrix[row - 1][column - 1] = 2;
	}

	t_node *head = &node[node_cnt++];
	head->x = 0;
	head->y = 0;
	head->prev = NULL;
	head->next = NULL;
	scanf("%d", &L);
	int dir = 1;
	int next_turn_time = 0;
    char turn_dir;
    for (int i = 0; i < L; i++)
    {
        scanf("%d %c", &next_turn_time, &turn_dir);
        while (time < next_turn_time)
        {
            time++;
            if (!move_snake(&head, dx[dir], dy[dir], matrix, N))
            {
                printf("%d\n", time);
                return 0;
            }
        }
        if (turn_dir == 'L')
        {
            dir = (dir + 3) % 4;
        }
        else if (turn_dir == 'D')
        {
            dir = (dir + 1) % 4;
        }
    }

    while (true)
    {
        time++;
        if (!move_snake(&head, dx[dir], dy[dir], matrix, N))
        {
            printf("%d\n", time);
            return 0;
        }
    }

    return 0;
}
