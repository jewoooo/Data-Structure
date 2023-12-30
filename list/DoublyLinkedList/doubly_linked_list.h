#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	node
{
	int			data;
	struct node	*prev;
	struct node	*next;
}	node;

node	*DLL_CreateNode(int new_data);
void	DLL_DestroyNode(node *node);
void	DLL_AppendNode(node **head, node *new_node);
void	DLL_InsertAfter(node *current, node *new_node);
void	DLL_RemoveNode(node **head, node *remove);
node	*DLL_GetNodeAt(node *head, int location);
int		DLL_GetNodeCount(node *head);

#endif