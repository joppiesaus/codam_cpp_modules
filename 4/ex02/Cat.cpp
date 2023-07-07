#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat()
{
    this->m_type = "Cat";
    this->m_brain = new Brain();
}

Cat::Cat(const Cat& other)
{
    *this = other;
}

Cat::~Cat()
{
    delete this->m_brain;
}

Cat& Cat::operator=(const Cat& rhs)
{
    this->m_type = rhs.m_type;
    this->m_brain = rhs.m_brain;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "purr" << std::endl;
    std::cout << "my ideas:" << std::endl;
    this->m_brain->displayIdeas();
}
