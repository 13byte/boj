#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum
{
	LEFT_PARENTHESIS = '(',
	RIGHT_PARENTHESIS = ')',
	PLUS = '+',
	MINUS = '-',
	MULTIPLY = '*',
	DIVIDE = '/',
	SPACE = ' ',
	OPERAND
} symbol;

typedef struct s_node
{
	char *data;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *list;
	t_node *top;
} t_stack;

void create_stack(t_stack **stack);
t_node *create_node(char *new_data);
void destroy_stack(t_stack *stack);
void destroy_node(t_node *node);
void push(t_stack *stack, t_node *new_node);
t_node *pop(t_stack *stack);
bool is_empty(t_stack *stack);
void get_postfix(char *infix, char *postfix);
int get_next_token(char *expr, char *token, int *type);
int get_priority(char op, bool in_stack);
bool cmp_prior(char op_in_stack, char op_in_token);
bool is_alpha(char cipher);

int main(void)
{
	char infix_expr[101];
	char postfix_expr[101];

	memset(infix_expr, 0, sizeof(infix_expr));
	memset(postfix_expr, 0, sizeof(postfix_expr));
	scanf("%s", infix_expr);
	get_postfix(infix_expr, postfix_expr);
	printf("%s\n", postfix_expr);
	return (0);
}

void create_stack(t_stack **stack)
{
	(*stack) = (t_stack *)malloc(sizeof(t_stack));
	(*stack)->list = NULL;
	(*stack)->top = NULL;
}

t_node *create_node(char *new_data)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));

	new_node->data = strdup(new_data);
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
	free(node->data);
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

void get_postfix(char *infix, char *postfix)
{
	t_stack *stack;
	char token[32];
	int type = -1;
	int position = 0;
	int length = strlen(infix);

	create_stack(&stack);
	while (position < length)
	{
		position += get_next_token(&infix[position], token, &type);
		if (type == OPERAND)
		{
			strcat(postfix, token);
		}
		else if (type == RIGHT_PARENTHESIS)
		{
			while (!(is_empty(stack)))
			{
				t_node *popped = pop(stack);

				if (popped->data[0] == LEFT_PARENTHESIS)
				{
					destroy_node(popped);
					break;
				}
				else
				{
					strcat(postfix, popped->data);
					destroy_node(popped);
				}
			}
		}
		else
		{
			while (!(is_empty(stack)) && !(cmp_prior(stack->top->data[0], token[0])))
			{
				t_node *popped = pop(stack);

				if (popped->data[0] != LEFT_PARENTHESIS)
					strcat(postfix, popped->data);
				destroy_node(popped);
			}
			push(stack, create_node(token));
		}
	}

	while (!(is_empty(stack)))
	{
		t_node *popped = pop(stack);

		if (popped->data[0] != LEFT_PARENTHESIS)
			strcat(postfix, popped->data);
		destroy_node(popped);
	}
	destroy_stack(stack);
}

int get_next_token(char *expr, char *token, int *type)
{
	int i = 0;

	for (; expr[i] != 0; ++i)
	{
		token[i] = expr[i];
		if (is_alpha(expr[i]))
		{
			*type = OPERAND;

			if (!(is_alpha(expr[i + 1])))
				break;
		}
		else
		{
			*type = expr[i];
			break;
		}
	}
	token[++i] = '\0';
	return (i);
}

int get_priority(char op, bool in_stack)
{
	int priority = -1;

	switch (op)
	{
	case LEFT_PARENTHESIS:
		priority = in_stack ? 3 : 0;
		break;
	case MULTIPLY:
	case DIVIDE:
		priority = 1;
		break;
	case PLUS:
	case MINUS:
		priority = 2;
		break;
	}
	return (priority);
}

bool is_alpha(char cipher)
{
	if (cipher >= 'A' && cipher <= 'Z')
		return (true);
	return (false);
}

bool cmp_prior(char op_in_stack, char op_in_token)
{
	return (get_priority(op_in_stack, true) > get_priority(op_in_token, false));
}