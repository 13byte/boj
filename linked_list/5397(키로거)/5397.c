#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	char data;
	struct s_node *prev;
	struct s_node *next;
} t_node;

t_node *create_node(char new_data)
{
	t_node *node = (t_node *)malloc(sizeof(t_node));

	node->data = new_data;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

void insert_after(t_node *cursor, char data)
{
	t_node *new_node = create_node(data);

	new_node->prev = cursor;
	new_node->next = cursor->next;
	if (cursor->next != NULL)
		cursor->next->prev = new_node;
	cursor->next = new_node;
}

void delete_node(t_node *cursor)
{
	if (cursor->prev != NULL)
		cursor->prev->next = cursor->next;
	if (cursor->next != NULL)
		cursor->next->prev = cursor->prev;
	free(cursor);
}

void process_input(t_node *head, char input)
{
	static t_node *cursor = NULL;

	if (head != NULL)
	{
		cursor = head;
		return;
	}
	if (input == '<')
	{
		if (cursor->prev != NULL)
		{
			cursor = cursor->prev;
		}
	}
	else if (input == '>')
	{
		if (cursor->next != NULL)
		{
			cursor = cursor->next;
		}
	}
	else if (input == '-')
	{
		if (cursor->prev != NULL)
		{
			cursor = cursor->prev;
			delete_node(cursor->next);
		}
	}
	else
	{
		insert_after(cursor, input);
		cursor = cursor->next;
	}
}

void process_test_case()
{
	char input[1000001];

	fgets(input, sizeof(input), stdin);
	input[strcspn(input, "\n")] = 0; // Remove newline character from fgets

	t_node *head = create_node('\0');
	process_input(head, '\0');

	int length = strlen(input);
	for (int i = 0; i < length; i++)
		process_input(NULL, input[i]);

	t_node *cursor = head->next;
	while (cursor != NULL)
	{
		printf("%c", cursor->data);
		cursor = cursor->next;
	}
	printf("\n");

	cursor = head;
	while (cursor != NULL)
	{
		t_node *next_node = cursor->next;
		free(cursor);
		cursor = next_node;
	}
}

int main(void)
{
	int test_cases;

	scanf("%d", &test_cases);
	getchar();
	while (test_cases--)
		process_test_case();
	return (0);
}