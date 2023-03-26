#include <stdio.h>
#include <stdlib.h>

typedef struct t_node
{
	int data;
	int index;
	struct t_node *prev;
	struct t_node *next;
} t_node;

t_node *cdll_create_node(int new_data, int new_index)
{
	t_node *new_node = malloc(sizeof(t_node));

	new_node->data = new_data;
	new_node->index = new_index;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void cdll_append_node(t_node **head, t_node *new_node)
{
	if (*head == NULL)
	{
		*head = new_node;
		(*head)->prev = *head;
		(*head)->next = *head;
	}
	else
	{
		t_node *tail = (*head)->prev;

		tail->next->prev = new_node;
		tail->next = new_node;
		new_node->next = *head;
		new_node->prev = tail;
	}
}

t_node *cdll_remove_node(t_node **head, t_node *remove)
{
	if (*head == remove)
	{
		if ((*head)->next == *head)
		{
			*head = NULL;
			return (*head);
		}
		else
		{
			(*head)->prev->next = remove->next;
			(*head)->next->prev = remove->prev;
			*head = remove->next;
		}
		free(remove);
		return (*head);
	}
	else
	{
		t_node *next = remove->next;

		remove->prev->next = remove->next;
		remove->next->prev = remove->prev;
		free(remove);
		return (next);
	}
}

int main(void)
{
	t_node *list = NULL;
	t_node *cursor;
	int n;
	int tmp;
	int data;

	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
	{
		scanf("%d", &tmp);
		cursor = cdll_create_node(tmp, i);
		cdll_append_node(&list, cursor);
	}
	cursor = list;
	while (list != NULL)
	{
		data = cursor->data;

		printf("%d ", cursor->index);
		cursor = cdll_remove_node(&list, cursor);
		if (data > 0)
			for (int i = 0; i < data - 1 && list != NULL; ++i)
				cursor = cursor->next;
		else
			for (int i = 0; i < -data && list != NULL; ++i)
				cursor = cursor->prev;
	}
	return (0);
}