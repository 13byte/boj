#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	int data;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *list;
	t_node *top;
} t_stack;

t_stack *create_stack();
void push(t_stack *stack, int new_data);
void pop(t_stack *stack);
void destroy_stack(t_stack *stack);
int is_empty(t_stack *stack);

int main(void)
{
	int N, P;
	int cnt = 0;
	t_stack *stack[6];

	for (int i = 0; i < 6; ++i)
		stack[i] = create_stack();
	scanf("%d %d", &N, &P);
	for (int i = 0; i < N; ++i)
	{
		int string, fret;
		scanf("%d %d", &string, &fret);
		string--;
		while (!(is_empty(stack[string])) && stack[string]->top->data > fret)
		{
			pop(stack[string]);
			cnt++;
		}
		if (is_empty(stack[string]) || stack[string]->top->data < fret)
		{
			push(stack[string], fret);
			cnt++;
		}
	}
	printf("%d\n", cnt);
	for (int i = 0; i < 6; ++i)
		destroy_stack(stack[i]);
	return (0);
}

t_stack *create_stack()
{
	t_stack *new_stack = (t_stack *)malloc(sizeof(t_stack));
	new_stack->list = NULL;
	new_stack->top = NULL;
	return (new_stack);
}

void push(t_stack *stack, int new_data)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));

	new_node->data = new_data;
	new_node->next = NULL;

	if (is_empty(stack))
		stack->list = new_node;
	else
		stack->top->next = new_node;
	stack->top = new_node;
}

void pop(t_stack *stack)
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
	free(top_node);
}

void destroy_stack(t_stack *stack)
{
	while (!is_empty(stack))
		pop(stack);
	free(stack);
}

int is_empty(t_stack *stack)
{
	return (stack->list == NULL);
}