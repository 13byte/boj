#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_node
{
	int position;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *list;
	t_node *top;
} t_stack;

t_stack *create_stack();
void push(t_stack *stack, int new_position);
void pop(t_stack *stack);
void destroy_stack(t_stack *stack);
int is_empty(t_stack *stack);
void calculate_area(t_stack *stack, int H[], int start, int end, int increment, int *result);

int main(void)
{
	int N, result = 0;
	int H[1000] = {
		0,
	};

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		int l, h;
		scanf("%d %d", &l, &h);
		H[l - 1] = h;
	}

	t_stack *S1 = create_stack();
	t_stack *S2 = create_stack();

	calculate_area(S1, H, 0, 1000, 1, &result);
	calculate_area(S2, H, 999, -1, -1, &result);

	result += (S2->top->position - S1->top->position + 1) * H[S1->top->position];

	printf("%d\n", result);

	destroy_stack(S1);
	destroy_stack(S2);
	return (0);
}

void calculate_area(t_stack *stack, int H[], int start, int end, int increment, int *result)
{
	for (int current_position = start; current_position != end; current_position += increment)
	{
		if (H[current_position] == 0)
			continue;
		if (is_empty(stack))
			push(stack, current_position);
		else
		{
			int prev_height = H[stack->top->position];
			if (H[current_position] > prev_height)
			{
				if (increment == 1)
					*result += (current_position - stack->top->position) * prev_height;
				else
					*result += (stack->top->position - current_position) * prev_height;
				push(stack, current_position);
			}
		}
	}
}

t_stack *create_stack()
{
	t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
	stack->list = NULL;
	stack->top = NULL;
	return (stack);
}

void push(t_stack *stack, int new_position)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));

	new_node->position = new_position;
	if (stack->list == NULL)
		stack->list = new_node;
	else
		stack->top->next = new_node;
	stack->top = new_node;
}

void pop(t_stack *stack)
{
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