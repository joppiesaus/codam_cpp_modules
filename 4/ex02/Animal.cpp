#include "Animal.hpp"

Animal::Animal() :
	m_type("Organism")
{
}

Animal::Animal(const Animal& other)
{
    *this = other;
}

Animal::~Animal()
{
    
}

Animal& Animal::operator=(const Animal& rhs)
{
    this->m_type = rhs.m_type;
	return *this;
}

std::string Animal::getType() const
{
    return this->m_type;
}
