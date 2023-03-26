#include <stdio.h>
#include <stdlib.h>

typedef struct t_node
{
	int location;
	struct t_node *prev;
	struct t_node *next;
} t_node;

t_node *cdll_create_node(int new_location)
{
	t_node *new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->location = new_location;
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
		t_node *tail;

		tail = (*head)->prev;
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
		t_node *next;

		next = remove->next;
		remove->prev->next = remove->next;
		remove->next->prev = remove->prev;
		free(remove);
		return (next);
	}
}

int main(void)
{
	t_node *list;
	t_node *cursor;
	int n;
	int k;

	list = NULL;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i)
	{
		cursor = cdll_create_node(i);
		cdll_append_node(&list, cursor);
	}
	cursor = list;
	printf("<");
	while (list != NULL)
	{
		for (int i = 1; i < k; ++i)
			cursor = cursor->next;
		printf("%d", cursor->location);
		cursor = cdll_remove_node(&list, cursor);
		if (list != NULL)
			printf(", ");
	}
	printf(">");
	return (0);
}