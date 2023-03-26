#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct t_node
{
	char data;
	struct t_node *prev;
	struct t_node *next;
} t_node;

t_node *create_node(char new_data)
{
	t_node *new_node = malloc(sizeof(t_node));

	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void append_node(t_node **head, t_node *new_node)
{
	if (*head == NULL)
	{
		(*head) = new_node;
		(*head)->prev = *head;
		(*head)->next = *head;
	}
	else
	{
		t_node *tail = (*head)->prev;

		tail->next->prev = new_node;
		tail->next = new_node;
		new_node->prev = tail;
		new_node->next = *head;
	}
}

int main(void)
{
	t_node *list = NULL;
	t_node *cursor;
	int n, k, s;
	char c;
	bool impossible = false;
	bool used[26] = {false};

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; ++i)
	{
		cursor = create_node(0);
		append_node(&list, cursor);
	}
	cursor = list;
	for (int i = 0; i < k && !impossible; ++i)
	{
		scanf("%d %c", &s, &c);
		for (int j = 0; j < s; ++j)
			cursor = cursor->next;
		if (cursor->data != 0 && cursor->data != c)
			impossible = true;
		else if (cursor->data == 0 && used[c - 'A'])
			impossible = true;
		else
		{
			used[c - 'A'] = true;
			cursor->data = c;
		}
	}
	if (impossible)
		printf("!");
	else
	{
		t_node *arrow = cursor;
		do
		{
			printf("%c", cursor->data ? cursor->data : '?');
			cursor = cursor->prev;
		} while (cursor != arrow);
	}
	return (0);
}