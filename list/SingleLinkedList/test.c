#include "single_linked_list.h"

int	main(void)
{
	int		i = 0;
	int		count = 0;
	node	*list = NULL;
	node	*current = NULL;
	node	*new_node = NULL;

	for (i = 0; i < 5; i++)
	{
		new_node = SLL_CreateNode(i);
		SLL_AppendNode(&list, new_node);
	}

	new_node = SLL_CreateNode(-1);
	SLL_InsertFront(&list, new_node);

	new_node = SLL_CreateNode(-2);
	SLL_InsertFront(&list, new_node);

	count = SLL_GetNodeCount(list);
	for (i = 0; i < count; i++)
	{
		current = SLL_GetNodeAt(list, i);
		printf("list[%d] : %d\n", i, current->data);
	}

	for (i = 0; i < count; i++)
	{
		current = SLL_GetNodeAt(list, 0);

		if (current != NULL)
		{
			SLL_RemoveNode(&list, current);
			SLL_DestroyNode(current);
		}
	}

	return (0);
}
