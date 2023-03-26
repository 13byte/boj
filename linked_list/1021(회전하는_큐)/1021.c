#include <stdio.h>
#include <stdlib.h>

typedef struct t_node
{
	int location;
	struct t_node *prev_node;
	struct t_node *next_node;
} t_node;

t_node *cdll_create_node(int new_location)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->location = new_location;
	new_node->prev_node = NULL;
	new_node->next_node = NULL;
	return (new_node);
}

void cdll_append_node(t_node **head, t_node *new_node)
{
	if (*head == NULL)
	{
		*head = new_node;
		(*head)->prev_node = *head;
		(*head)->next_node = *head;
	}
	else
	{
		t_node *tail;

		tail = (*head)->prev_node;
		tail->next_node->prev_node = new_node;
		tail->next_node = new_node;
		new_node->next_node = *head;
		new_node->prev_node = tail;
	}
}

t_node *cdll_remove_node(t_node *remove)
{
	t_node *return_node;

	return_node = remove->next_node;
	remove->prev_node->next_node = remove->next_node;
	remove->next_node->prev_node = remove->prev_node;
	remove->prev_node = NULL;
	remove->next_node = NULL;

	free(remove);
	return (return_node);
}

int main(void)
{
	t_node *list = NULL;
	t_node *cursor = NULL;
	t_node *left_cursor = NULL;
	t_node *right_cursor = NULL;
	int n = 0;
	int m = 0;
	int cnt = 0;
	int find = 0;

	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; ++i)
	{
		cursor = cdll_create_node(i);
		cdll_append_node(&list, cursor);
	}
	cursor = list;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &find);

		int left_moves = 0;
		int right_moves = 0;
		left_cursor = cursor;
		right_cursor = cursor;

		while (left_cursor->location != find)
		{
			left_cursor = left_cursor->prev_node;
			left_moves++;
		}
		while (right_cursor->location != find)
		{
			right_cursor = right_cursor->next_node;
			right_moves++;
		}
		if (left_moves <= right_moves)
		{
			cnt += left_moves;
			cursor = left_cursor;
		}
		else
		{
			cnt += right_moves;
			cursor = right_cursor;
		}
		cursor = cdll_remove_node(cursor);
	}
	printf("%d\n", cnt);
	return (0);
}