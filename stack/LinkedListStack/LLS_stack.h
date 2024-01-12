#ifndef LS_STACK_H
#define LS_STACK_H

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode
{
	int				Data;
	struct tagNode	*Next;
} Node;

typedef struct tagLinkedListStack
{
	Node	*Head;
	Node	*Top;
} LinkedListStack;

void	LLS_CreateStack(LinkedListStack **stack);
void	LLS_DestroyStack(LinkedListStack *stack);

Node	*LLS_CreateNode(int data);
void	LLS_DestroyNode(Node *node);

void	LLS_Push(LinkedListStack *stack, Node *new_node);
Node	*LLS_Pop(LinkedListStack *stack);

Node	*LLS_Top(LinkedListStack *stack);
int		LLS_GetSize(LinkedListStack *stack);
int		LLS_IsEmpty(LinkedListStack *stack);

#endif
