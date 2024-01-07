#include "singly_linked_list.h"

// Create node

node	*SLL_CreateNode(int new_data)
{
	node	*new_node = (node *)malloc(sizeof(node));

	new_node->data = new_data;
	new_node->next = NULL;

	return (new_node);
}

// Append node

void	SLL_AppendNode(node **head, node *new_node)
{
	node	*tail = NULL;

	if ((*head) == NULL)
		(*head) = new_node;
	else
	{
		tail = (*head);
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = new_node;
	}
}

// Get node at

node	*SLL_GetNodeAt(node *head, int location)
{
	node	*current = head;

	while (current != NULL && (--location) >= 0)
	{
		current = current->next;
	}
	return (current);
}

// Insert node after current

void	SLL_InsertAfter(node *current, node *new_node)
{
	new_node->next = current->next;
	current->next = new_node;
}

// Insert node before current

void	SLL_InsertBefore(node **head, node *current, node *new_node)
{
	node	*before_current = (*head);

	while (before_current->next != current)
	{
		before_current = before_current->next;
	}
	before_current->next = new_node;
	new_node->next = current;
}

// Insert node at head

void	SLL_InsertFront(node **head, node *new_head)
{
	if ((*head) == NULL)
		(*head) = new_head;
	else
	{
		new_head->next = (*head);
		(*head) = new_head;
	}
}

// Remove node in List

void	SLL_RemoveNode(node **head, node *remove)
{
	node	*current = NULL;

	if ((*head) == remove)
		(*head) = remove->next;
	else
	{
		current = (*head);
		while (current != NULL && current->next != remove)
		{
			current = current->next;
		}
		if (current != NULL)
			current->next = remove->next;
	}
}

// Destroy node

void	SLL_DestroyNode(node *node)
{
	free(node);
}

// Destroy all nodes

void	SLL_DestroyAllNode(node **list)
{
	node	*temp = NULL;

	while ((*list) != NULL)
	{
		temp = (*list);
		(*list) = (*list)->next;
		SLL_DestroyNode(temp);
	}
}

// Get node's count

int		SLL_GetNodeCount(node *head)
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