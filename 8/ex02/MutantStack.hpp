/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/13 16:42:26 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/13 17:38:19 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stack>

template <class T, class Container = std::deque<T> >
class MutantStack: public std::stack<T, Container>
{
public:

	typedef typename std::stack<T, Container>::container_type	container_type;

	typedef typename container_type::iterator					iterator;
	typedef typename container_type::reverse_iterator			reverse_iterator;
	typedef typename container_type::const_iterator				const_iterator;
	typedef typename container_type::const_reverse_iterator		const_reverse_iterator;

	MutantStack() : std::stack<T, Container>() {}
	~MutantStack() {}
	MutantStack(const MutantStack& other)
	{
		*this = other;
	}

	MutantStack& operator=(const MutantStack<T, Container>& rhs)
	{
		if (*this != rhs)
		{
			this->c = rhs.c;
		}
		return *this;
	}


	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

	const_iterator begin() const
	{
		return this->c.begin();
	}

	const_iterator end() const
	{
		return this->c.end();
	}

	reverse_iterator rbegin()
	{
		return this->c.rbegin();
	}

	reverse_iterator rend()
	{
		return this->c.rend();
	}

	const_reverse_iterator rbegin() const
	{
		return this->c.rbegin();
	}

	const_reverse_iterator rend() const
	{
		return this->c.rend();
	}
};
