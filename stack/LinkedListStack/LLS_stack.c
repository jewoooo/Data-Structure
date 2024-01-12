#include "LS_stack.h"

void	LLS_CreateStack(LinkedListStack **stack)
{
	(*stack) = (LinkedListStack *)malloc(sizeof(LinkedListStack));

	(*stack)->Head = NULL;
	(*stack)->Top = NULL;
}

void	LLS_DestroyStack(LinkedListStack *stack)
{
	if (LLS_IsEmpty(stack) != 1)
	{
		Node	*popped = LLS_Pop(stack);
		LLS_DestroyNode(popped);
	}
	free(stack);
}

Node	*LLS_CreateNode(int data)
{
	Node	*new_node = (Node *)malloc(sizeof(Node));

	new_node->Data = data;
	new_node->Next = NULL;

	return (new_node);
}

void	LLS_DestroyNode(Node *node)
{
	free(node);
}

void	LLS_Push(LinkedListStack *stack, Node *new_node)
{
	if (stack->Head == NULL)
		stack->Head = new_node;
	else
		(stack->Top)->Next = new_node;
	stack->Top = new_node;
}

// Pop LLS's Top and Set new Top on the LLS.
Node	*LLS_Pop(LinkedListStack *stack)
{
	Node	*popped = stack->Top;

	if (stack->Head == stack->Top)
	{
		stack->Head = NULL;
		stack->Top = NULL;
	}
	else
	{
		Node	*new_top = stack->Head;
		while (new_top != NULL && new_top->Next != stack->Top)
		{
			new_top = new_top->Next;
		}
		stack->Top = new_top;
		new_top->Next = NULL;
	}

	return (popped);
}

Node	*LLS_Top(LinkedListStack *stack)
{
	return (stack->Top);
}

int		LLS_GetSize(LinkedListStack *stack)
{
	int		size = 0;
	Node	*temp = stack->Head;

	while (temp != NULL)
	{
		temp = temp ->Next;
		size++;
	}

	return (size);
}

int		LLS_IsEmpty(LinkedListStack *stack)
{
	if (stack->Head == NULL)
		return (1);
	else
		return (0);
}
