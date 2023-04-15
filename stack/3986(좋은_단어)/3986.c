#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	char data;
} t_node;

typedef struct s_stack
{
	int capacity;
	int top;
	t_node *nodes;
} t_stack;

t_stack *create_stack(int capacity);
void push(t_stack *stack, char new_data);
void pop(t_stack *stack);
void destroy_stack(t_stack *stack);
int is_empty(t_stack *stack);

int main(void)
{
	int n, count = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		t_stack *stack = create_stack(100001);
		char word[100001];
		scanf("%s", word);
		int length = strlen(word);

		for (int j = 0; j < length; ++j)
		{
			if (is_empty(stack) || stack->nodes[stack->top].data != word[j])
				push(stack, word[j]);
			else
				pop(stack);
		}
		if (is_empty(stack))
			count++;
		destroy_stack(stack);
	}

	printf("%d\n", count);
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

void push(t_stack *stack, char new_data)
{
	stack->top++;
	stack->nodes[stack->top].data = new_data;
}

void pop(t_stack *stack)
{
	stack->top--;
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