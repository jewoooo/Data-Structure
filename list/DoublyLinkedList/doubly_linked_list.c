#include "doubly_linked_list.h"

// Create new node

node	*DLL_CreateNode(int new_data)
{
	node	*new_node = (node *)malloc(sizeof(node));

	new_node->data = new_data;
	new_node->prev = NULL;
	new_node->next = NULL;

	return (new_node);
}

// Destroy node

void	DLL_DestroyNode(node *node)
{
	free(node);
}

// Append new node

void	DLL_AppendNode(node **head, node *new_node)
{
	node	*tail = NULL;

	if ((*head) == NULL)
		(*head) = new_node;
	else
	{
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = new_node;
		new_node->prev = tail;
	}
}

// Insert new node after current node

void	DLL_InsertAfter(node *current, node *new_node)
{
	new_node->next = current->next;
	new_node->prev = current;

	if (current->next != NULL)
	{
		current->next->prev = new_node;
		current->next = new_node;
	}
}

// Remoe node in the list

void	DLL_RemoveNode(node **head, node *remove)
{
	node	*temp = NULL;

	if ((*head) == remove)
	{
		(*head) = remove->next;
		if ((*head) != NULL)
			(*head)->prev = NULL;
		remove->prev = NULL;
		remove->next = NULL;
	}
	else
	{
		temp = remove;
		if (remove->prev != NULL)
			remove->prev->next = temp->next;
		if (remove->next != NULL)
			remove->next->prev = temp->prev;
		remove->prev = NULL;
		remove->next = NULL;
	}
}

// Get node in the list

node	*DLL_GetNodeAt(node *head, int location)
{
	node	*current = head;

	while (current != NULL && (--location) >= 0)
	{
		current = current->next;
	}
	return (current);
}

// Get counts of the nodes in the list

int	DLL_GetNodeCount(node *head)
{
	int		count = 0;
	node	*current = head;

	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}