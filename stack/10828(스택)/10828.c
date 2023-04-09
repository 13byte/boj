#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int element_type;

typedef struct s_node
{
	element_type data;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *list;
	t_node *top;
} t_stack;

void create_stack(t_stack **stack);
t_node *create_node(element_type new_data);
void destroy_stack(t_stack *stack);
void destroy_node(t_node *node);
void push(t_stack *stack, t_node *new_node);
t_node *pop(t_stack *stack);
t_node *top(t_stack *stack);
int get_size(t_stack *stack);
int is_empty(t_stack *stack);

int main(void)
{
	t_stack *stack;
	t_node *popped;
	int N;
	char command[7];
	int X;

	scanf("%d", &N);
	create_stack(&stack);
	while (N--)
	{
		scanf("%s", command);
		if (strcmp(command, "push") == 0)
		{
			scanf("%d", &X);
			push(stack, create_node(X));
		}
		else if (strcmp(command, "pop") == 0)
		{
			popped = pop(stack);
			if (popped == NULL)
				printf("-1\n");
			else
			{
				printf("%d\n", popped->data);
				destroy_node(popped);
			}
		}
		else if (strcmp(command, "size") == 0)
		{
			printf("%d\n", get_size(stack));
		}
		else if (strcmp(command, "empty") == 0)
		{
			printf("%d\n", is_empty(stack));
		}
		else if (strcmp(command, "top") == 0)
		{
			popped = top(stack);
			if (popped == NULL)
				printf("-1\n");
			else
			{
				printf("%d\n", popped->data);
			}
		}
	}
	destroy_stack(stack);
	return (0);
}

void create_stack(t_stack **stack)
{
	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	(*stack)->list = NULL;
	(*stack)->top = NULL;
}

t_node *create_node(element_type new_data)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));

	new_node->data = new_data;
	new_node->next = NULL;
	return (new_node);
}

void destroy_stack(t_stack *stack)
{
	while (!(is_empty(stack)))
	{
		t_node *popped = pop(stack);
		destroy_node(popped);
	}
	free(stack);
}

void destroy_node(t_node *node)
{
	free(node);
}

void push(t_stack *stack, t_node *new_node)
{
	if (stack->list == NULL)
		stack->list = new_node;
	else
		stack->top->next = new_node;
	stack->top = new_node;
}

t_node *pop(t_stack *stack)
{
	if (is_empty(stack))
	{
		return NULL;
	}
	t_node *top_node = stack->top;

	if (stack->list == stack->top)
	{
		stack->list = NULL;
		stack->top = NULL;
	}
	else
	{
		t_node *cursor = stack->list;

		while (cursor != NULL && cursor->next != stack->top)
			cursor = cursor->next;
		stack->top = cursor;
		stack->top->next = NULL;
	}
	return (top_node);
}

t_node *top(t_stack *stack)
{
	return (stack->top);
}

int get_size(t_stack *stack)
{
	t_node *cursor = stack->list;
	int cnt = 0;

	while (cursor != NULL)
	{
		cursor = cursor->next;
		cnt++;
	}
	return (cnt);
}

int is_empty(t_stack *stack)
{
	return (stack->list == NULL);
}