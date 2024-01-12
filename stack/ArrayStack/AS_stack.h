#ifndef AS_STACK_H
#define AS_STACK_H

#include <stdlib.h>
#include <stdio.h>

typedef struct tagNode
{
	int	Data;
} Node;

typedef struct tagArrayStack
{
	int		Capacity;
	int 	Top;
	Node	*Nodes;
} ArrayStack;

void	AS_CreateStackArray(ArrayStack **stack, int capacity);
void	AS_DestroyStack(ArrayStack *stack);
void	AS_Push(ArrayStack *stack, int data);
int		AS_Pop(ArrayStack *stack);
int		AS_Top(ArrayStack *stack);
int		AS_GetSize(ArrayStack *stack);
int		AS_IsEmpty(ArrayStack *stack);
int		AS_IsFull(ArrayStack *stack);

#endif