/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jobvan-d <jobvan-d@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/01 17:47:11 by jobvan-d      #+#    #+#                 */
/*   Updated: 2022/09/02 16:22:49 by jobvan-d      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Form.hpp"

class RobotomyRequestForm: public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

	void execute(const Bureaucrat& executor) const;

private:
	std::string m_target;
};
