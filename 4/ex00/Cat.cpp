#include "Cat.hpp"

Cat::Cat()
{
    this->m_type = "Cat";
}

Cat::Cat(const Cat& a)
{
    *this = a;
}

Cat::~Cat()
{
    
}

Cat& Cat::operator=(const Cat& rhs)
{
    this->m_type = rhs.m_type;
	return *this;
}

void Cat::makeSound() const
{
    std::cout << "purr" << std::endl;
}
