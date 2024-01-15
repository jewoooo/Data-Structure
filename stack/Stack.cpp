#include <iostream>
#include <stack>

int	main(void)
{
	std::stack<int>		S;
	// std::stack<char>	S2;

	S.push(1);
	S.push(2);
	int	s_size = S.size();
	std::cout << "Stack's size is " << s_size << '\n';
	S.pop();
	S.pop();
	if (S.empty())
	{
		std::cout << "Stack is empty\n"; 
	}
	return (0);
}