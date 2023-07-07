/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Array.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/08 14:37:25 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/08 17:23:31 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template<class T>
class Array
{
public:
	Array() : m_size(0)
	{
		this->m_arr = new T[0];
	}

	Array(unsigned int n) : m_size(n)
	{
		this->m_arr = new T[n];

		for (unsigned int i = 0; i < n; i++)
		{
			this->m_arr[i] = T();
		}
	}

	~Array()
	{
		delete[] this->m_arr;
	}

	Array(const Array& other)
	{
		this->m_arr = nullptr;
		*this = other;
	}

	Array& operator=(const Array& rhs)
	{
		if (this->m_arr != nullptr)
		{
			delete[] this->m_arr;
		}

		this->m_size = rhs.size();
		this->m_arr = new T[this->m_size];

		for (size_t i = 0; i < this->m_size; i++)
		{
			this->m_arr[i] = const_cast<Array<T>&>(rhs)[i];
		}
		return *this;
	}

	T& operator[](size_t index)
	{
		if (index >= this->m_size)
		{
			throw std::exception();
		}
		return this->m_arr[index];
	}

	size_t size() const
	{
		return m_size;
	}

	void display() const
	{
		if (this->m_size > 0)
		{
			for (size_t i = 0; i < this->m_size - 1; i++)
			{
				std::cout << this->m_arr[i] << ", ";
			}
			std::cout << this->m_arr[this->m_size - 1] << std::endl;
		}
		else
		{
			std::cout << "(array empty)" << std::endl;
		}
	}

private:
	T* m_arr;
	size_t m_size;
};
