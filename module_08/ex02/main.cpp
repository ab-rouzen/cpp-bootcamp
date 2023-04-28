#include "MutantStack.hpp"
#include <iostream>
#include <list>

int	main(void)
{
{	
	MutantStack<int>	s;

	s.push(7);
	s.push(4);
	s.push(0);
	s.push(10);
	s.push(-12);
	MutantStack<int>::iterator beginIt = s.begin();
	MutantStack<int>::iterator endIt = s.end();
	std::cout << "!-------- Iterator --------!" << std::endl;
	for (; beginIt != endIt; beginIt++)\
	{
		std::cout << *beginIt << std::endl;
	}
	std::cout << "!--------   Top()  --------!" << std::endl;
	for (;!s.empty();)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}
}
	//system("leaks stackful" );
	return 0;
}

/* Example with list */

// int main()
// {
// 	std::list<int> mstack;
// 	mstack.push_back(5);
// 	mstack.push_back(17);
// 	std::cout << mstack.back() << std::endl;
// 	mstack.pop_back();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push_back(3);
// 	mstack.push_back(5);
// 	mstack.push_back(737);
// 	//[...]
// 	mstack.push_back(0);
// 	std::list<int>::iterator it = mstack.begin();
// 	std::list<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	//std::stack<int> s(mstack);
// 	return 0;
// }

/* Original example */

// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }
