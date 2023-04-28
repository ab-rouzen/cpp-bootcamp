#ifndef	MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <stack>

template<class T>
class	MutantStack : public std::stack<T>
{
	public:
		typedef	typename std::stack<T>::container_type::iterator 		iterator;
		typedef	typename std::stack<T>::container_type::const_iterator	const_iterator;
		
		MutantStack()  : std::stack<T>::stack()
		{};
		MutantStack(const MutantStack& copy) : std::stack<T>::stack(copy)
		{};
		MutantStack&	operator=(const MutantStack& copy)
		{
			std::stack<T>::operator=(copy);
		};
		~MutantStack()
		{};
		iterator	begin()
		{
			return (std::stack<T>::c.begin());
		};
		const iterator	begin() const
		{
			return (std::stack<T>::c.begin());
		};
		iterator	end()
		{
			return (std::stack<T>::c.end());
		};
		const iterator	end() const
		{
			return (std::stack<T>::c.end());
		};
};

#endif	// ! MUTANT_STACK_HPP