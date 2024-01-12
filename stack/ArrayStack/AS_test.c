#include "AS_stack.h"

int	main(void)
{
	int	i = 0;
	ArrayStack *stack = NULL;

	AS_CreateStackArray(&stack, 10);

	AS_Push(stack, 1);
	AS_Push(stack, 2);
	AS_Push(stack, 3);
	AS_Push(stack, 4);

	printf("Capacity: %d\nSize: %d\nTop: %d\n",
			stack->Capacity, AS_GetSize(stack), AS_Top(stack));
	
	for (i = 0; i < 4; i++)
	{
		if (AS_IsEmpty(stack))
			break ;
	
		printf("Popped: %d\n", AS_Pop(stack));

		if (!AS_IsEmpty(stack))
			printf("Current top: %d\n", AS_Top(stack));
		else
			printf("Stack is Empty.\n");
	}
}
