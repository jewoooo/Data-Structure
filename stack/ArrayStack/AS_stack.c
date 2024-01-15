#include "AS_stack.h"

// Create Stack's struct for infos and ArrayStack
void	AS_CreateStack(ArrayStack **stack, int capacity)
{
	(*stack) = (ArrayStack *)malloc(sizeof(ArrayStack));
	(*stack)->Nodes = (Node *)malloc(sizeof(Node) * capacity);

	(*stack)->Capacity = capacity;
	(*stack)->Top = -1;
}

// Destroy ArrayStack and Stack's struct
void	AS_DestroyStack(ArrayStack *stack)
{
	free(stack->Nodes);
	free(stack);
}

// Push data in the ArrayStack
void	AS_Push(ArrayStack *stack, int data)
{
	(stack->Top)++;
	stack->Nodes[stack->Top].Data = data;
}

// Pop data
int	AS_Pop(ArrayStack *stack)
{
	int	return_index = (stack->Top)--;

	return ((stack->Nodes)[return_index].Data);
}

// Pop Top's data in the ArrayStack.
int	AS_Top(ArrayStack *stack)
{
	return ((stack->Nodes)[stack->Top].Data);
}

// Get AS's size.
int	AS_GetSize(ArrayStack *stack)
{
	return ((stack->Top) + 1);
}

// Check the Stack whether it is Empty or not.
int	AS_IsEmpty(ArrayStack *stack)
{
	if (stack->Top == -1)
		return (1);
	else
		return (0);
}

// Check ArrayStack whether it is full or not.
int	AS_IsFull(ArrayStack *stack)
{
	if (stack->Capacity == stack->Top + 1)
		return (1);
	else
		return (0);
}
