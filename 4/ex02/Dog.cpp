#include "Dog.hpp"

#include "Brain.hpp"

Dog::Dog()
{
    this->m_type = "Dog";
    this->m_brain = new Brain();
}

Dog::Dog(const Dog& other)
{
    *this = other;
}

Dog::~Dog()
{
    delete this->m_brain;   
}

Dog& Dog::operator=(const Dog& rhs)
{
    this->m_type = rhs.m_type;
    this->m_brain = rhs.m_brain;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "bark" << std::endl;
}
