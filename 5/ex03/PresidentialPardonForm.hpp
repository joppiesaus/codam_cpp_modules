/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 17:47:11 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/02 16:32:50 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

	void execute(const Bureaucrat& executor) const;

private:
	std::string m_target;
};
