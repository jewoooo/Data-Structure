#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int			data;
	struct node	*next;
} node;

node	*SLL_CreateNode(int new_data);
void	SLL_AppendNode(node **head, node *new_node);
node	*SLL_GetNodeAt(node *head, int location);
void	SLL_InsertAfter(node *current, node *new_node);
void	SLL_InsertBefore(node **head, node *current, node *new_node);
void	SLL_InsertFront(node **head, node *new_head);
void	SLL_RemoveNode(node **head, node *remove);
void	SLL_DestroyNode(node *node);
void	SLL_DestroyAllNode(node **list);
int		SLL_GetNodeCount(node *head);

#endif