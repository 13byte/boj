#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	char data;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *top;
	int size;
} t_stack;

t_stack *init_stack()
{
	t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

void destroy_stack(t_stack *stack)
{
	while (!(is_empty(stack)))
		pop(stack);
	free(stack);
}

void push(t_stack *stack, char new_data) // Changed to char
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = new_data; // Removed strdup()
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

char pop(t_stack *stack)
{
	if (is_empty(stack))
		return ('\0');

	t_node *top_node = stack->top;

	char data = top_node->data;
	stack->top = top_node->next;
	stack->size--;
	free(top_node);
	return (data);
}

t_node *top(t_stack *stack)
{
	return (stack->top);
}

int get_size(t_stack *stack)
{
	return (stack->size);
}

int is_empty(t_stack *stack)
{
	return (stack->top == NULL);
}

int main(void)
{
	t_stack *stack;
	char str[51];
	int T;

	scanf("%d", &T);
	stack = init_stack();

	for (int i = 0; i < T; i++)
	{
		scanf("%s", str);

		int is_valid = 1;

		for (int j = 0; j < strlen(str); j++)
		{
			if (str[j] == '(')
			{
				push(stack, str[j]);
			}
			else if (str[j] == ')')
			{
				if (is_empty(stack))
				{
					is_valid = 0;
					break;
				}
				pop(stack);
			}
		}

		if (!is_empty(stack))
		{
			is_valid = 0;
			while (!is_empty(stack))
			{
				pop(stack);
			}
		}

		if (is_valid)
			printf("YES\n");
		else
			printf("NO\n");
	}

	destroy_stack(stack);
	return (0);
}
