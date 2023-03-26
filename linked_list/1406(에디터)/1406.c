#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	char c;
	struct s_node *prev;
	struct s_node *next;
} t_node;

t_node *create_node(char new_c)
{
	t_node *new_node = malloc(sizeof(t_node));

	new_node->c = new_c;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_node *append_node(t_node **head, t_node *new_node, t_node **tail)
{
	if (*head == NULL)
	{
		*head = new_node;
		*tail = new_node;
	}
	else
	{
		(*tail)->next = new_node;
		new_node->prev = *tail;
		*tail = new_node;
	}

	return (new_node);
}

void remove_node(t_node **head, t_node *cursor)
{
	t_node *remove = cursor->prev;

	if (remove->prev != NULL)
		remove->prev->next = cursor;
	else
		*head = cursor;

	cursor->prev = remove->prev;
	remove->prev = NULL;
	remove->next = NULL;
	free(remove);
}

void insert_before_node(t_node **head, t_node *cursor, t_node *new_node)
{
	new_node->next = cursor;

	if (cursor->prev != NULL)
	{
		new_node->prev = cursor->prev;
		cursor->prev->next = new_node;
	}
	else
	{
		new_node->prev = NULL;
		*head = new_node;
	}

	cursor->prev = new_node;
}

void printing_all_nodes(t_node **head)
{
	t_node *cursor = *head;
	while (cursor != NULL)
	{
		printf("%c", cursor->c);
		cursor = cursor->next;
	}
}

int main(void)
{
	t_node *list = NULL;
	t_node *tail = list;
	t_node *cursor;
	int m;
	char command;
	char c;

	while ((c = getchar()) != '\n')
	{
		cursor = create_node(c);
		tail = append_node(&list, cursor, &tail);
	}
	cursor = create_node('\n');
	tail = append_node(&list, cursor, &tail);
	scanf("%d", &m);
	getchar();
	for (int i = 0; i < m; ++i)
	{
		scanf(" %c", &command);
		if (command == 'L' && cursor != list)
			cursor = cursor->prev;
		if (command == 'D' && cursor != tail)
			cursor = cursor->next;
		if (command == 'B' && cursor != list)
			remove_node(&list, cursor);
		if (command == 'P')
		{
			scanf(" %c", &c);
			insert_before_node(&list, cursor, create_node(c));
		}
	}
	printing_all_nodes(&list);

	return (0);
}