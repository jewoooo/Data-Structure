#ifndef CIRCULAR_DOUBLY_LINKED_LIST_H
#define CIRCULAR_DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct	node
{
	int			data;
	struct node	*prev;
	struct node	*next;
}	node;

node	*CDLL_CreateNode(int new_data);
void	CDLL_DestroyNode(node *node);
void	CDLL_AppendNode(node **head, node *new_node);
void	CDLL_InsertAfter(node *current, node *new_node);
void	CDLL_RemoveNode(node **head, node *remove);
node	*CDLL_GetNodeAt(node *head, int location);
int		CDLL_GetNodeCount(node *head);

#endif