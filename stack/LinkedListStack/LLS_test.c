#include "LLS_stack.h"

int	main(void)
{
	int		i = 0;
	int		size = 0;
	Node	*popped;
	LinkedListStack	*stack;

	LLS_CreateStack(&stack);
	LLS_Push(stack, LLS_CreateNode(1));
	LLS_Push(stack, LLS_CreateNode(2));
	LLS_Push(stack, LLS_CreateNode(3));
	LLS_Push(stack, LLS_CreateNode(4));

	size = LLS_GetSize(stack);
	printf("Size: %d\nTop: %d\n", size, LLS_Top(stack)->Data);
	
	for (i = 0; i < size; i++)
	{
		if (LLS_IsEmpty(stack))
			break ;
		popped = LLS_Pop(stack);

		printf("Popped: %d\n", popped->Data);

		LLS_DestroyNode(popped);
		if (!LLS_IsEmpty(stack))
		{
			printf("Current Top: %d\n", LLS_Top(stack)->Data);
		}
		else
		{
			printf("Stack is Empty");
		}
	}
	LLS_DestroyStack(stack);

	return (0);
}