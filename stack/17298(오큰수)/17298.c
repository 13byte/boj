#include <stdio.h>
#include <stdlib.h>

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
	int n;
	int arr[1000001];
	int ans[1000001];

	scanf("%d", &n);
	t_stack *stack = create_stack(n);

	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	for (int i = n - 1; i >= 0; --i)
	{
		while (!is_empty(stack) && stack->nodes[stack->top].data <= arr[i])
			pop(stack);
		if (is_empty(stack))
			ans[i] = -1;
		else
			ans[i] = stack->nodes[stack->top].data;
		push(stack, arr[i]);
	}

	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
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