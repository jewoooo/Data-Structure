#include "circular_doubly_linked_list.h"

node	*CDLL_CreateNode(int new_data)
{
	node	*new_node = (node *)malloc(sizeof(node));

	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

void	CDLL_DestroyNode(node *node)
{
	free(node);
}

void	CDLL_AppendNode(node **head, node *new_node)
{
	node	*tail = NULL;

	if ((*head) == NULL)
	{
		(*head) = new_node;
		(*head)->next = (*head);
		(*head)->prev = (*head);
	}
	else
	{
		tail = (*head)->prev;
	
		tail->next->prev = new_node;
		tail->next = new_node;

		new_node->next = (*head);
		new_node->prev = tail;
	}
}

void	CDLL_InsertAfter(node *current, node *new_node)
{
	new_node->next = current->next;
	new_node->prev = current;

	if (current->next != NULL)
	{
		current->next->prev = new_node;
		current->next = new_node;
	}
}

void	CDLL_RemoveNode(node **head, node *remove)
{
	if ((*head) == remove)
	{
		(*head)->prev->next = remove->next;
		(*head)->next->prev = remove->prev;

		(*head) = remove->next;

		remove->prev = NULL;
		remove->next = NULL;
	}
	else
	{
		remove->prev->next = remove->next;
		remove->next->prev = remove->prev;

		remove->prev = NULL;
		remove->next = NULL;
	}
}

node	*CDLL_GetNodeAt(node *head, int location)
{
	node	*current = head;

	while (current != NULL && (--location) >= 0)
	{
		current = current->next;
	}

	return (current);
}

int		CDLL_GetNodeCount(node *head)
{
	int		count = 0;
	node	*tail = head;

	while (tail != NULL) // Because it can be NULL list.
	{
		tail = tail->next;
		count++;
		if (tail == head)
			break ;
	}

	return (count);
}
