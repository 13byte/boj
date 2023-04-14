#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct s_node
{
	double data;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *list;
	t_node *top;
} t_stack;

void create_stack(t_stack **stack);
t_node *create_node(double new_data);
void destroy_stack(t_stack *stack);
void destroy_node(t_node *node);
void push(t_stack *stack, t_node *new_node);
t_node *pop(t_stack *stack);
bool is_empty(t_stack *stack);

int main(void)
{
	int n;
	char expr[101];
	double values[26];
	t_stack *stack;

	scanf("%d", &n);
	scanf("%s", expr);
	for (int i = 0; i < n; ++i)
		scanf("%lf", &values[i]);
	create_stack(&stack);
	for (int i = 0; expr[i] != '\0'; ++i)
	{
		char c = expr[i];

		if ('A' <= c && c <= 'Z')
		{
			push(stack, create_node(values[c - 'A']));
		}
		else
		{
			t_node *node_b = pop(stack);
			t_node *node_a = pop(stack);

			double a = node_a->data;
			double b = node_b->data;
			double result;

			switch (c)
			{
			case '+':
				result = a + b;
				break;
			case '-':
				result = a - b;
				break;
			case '*':
				result = a * b;
				break;
			case '/':
				result = a / b;
				break;
			}

			push(stack, create_node(result));

			destroy_node(node_a);
			destroy_node(node_b);
		}
	}

	printf("%.2lf\n", stack->top->data);

	destroy_stack(stack);

	return (0);
}

void create_stack(t_stack **stack)
{
	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	(*stack)->list = NULL;
	(*stack)->top = NULL;
}

t_node *create_node(double new_data)
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

bool is_empty(t_stack *stack)
{
	return (stack->list == NULL);
}