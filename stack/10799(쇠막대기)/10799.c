#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	int data;
} t_node;

typedef struct s_stack
{
	int capacity;
	int top;
	t_node *nodes;
} t_stack;

t_stack *create_stack(int capacity);
void push(t_stack *stack, int new_data);
int pop(t_stack *stack);
void destroy_stack(t_stack *stack);
int is_empty(t_stack *stack);

int main(void)
{
	char input[100001];
	scanf("%s", input);
	int length = strlen(input);
	t_stack *stack = create_stack(length);

	int result = 0;
	for (int i = 0; i < length; i++)
	{
		if (input[i] == '(')
			push(stack, i);
		else
		{
			if (stack->nodes[stack->top].data == i - 1)
			{
				pop(stack);
				result += stack->top + 1;
			}
			else
			{
				pop(stack);
				result++;
			}
		}
	}
	printf("%d\n", result);
	destroy_stack(stack);
	return (0);
}

t_stack *create_stack(int capacity)
{
	t_stack *new_stack = (t_stack *)malloc(sizeof(t_stack));

	new_stack->nodes = (t_node *)malloc(sizeof(t_node) * capacity);
	new_stack->capacity = capacity;
	new_stack->top = -1;
	return (new_stack);
}

void push(t_stack *stack, int new_data)
{
	stack->nodes[++stack->top].data = new_data;
}

int pop(t_stack *stack)
{
	if (is_empty(stack))
		return 0;
	return (stack->nodes[stack->top--].data);
}

void destroy_stack(t_stack *stack)
{
	free(stack->nodes);
	free(stack);
}

int is_empty(t_stack *stack)
{
	return (stack->top == -1);
}