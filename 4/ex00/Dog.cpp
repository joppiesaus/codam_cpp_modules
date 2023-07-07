#include "Dog.hpp"

Dog::Dog()
{
    this->m_type = "Dog";
}

Dog::Dog(const Dog& other)
{
    *this = other;
}

Dog::~Dog()
{
    
}

Dog& Dog::operator=(const Dog& rhs)
{
    this->m_type = rhs.m_type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "bark" << std::endl;
}
