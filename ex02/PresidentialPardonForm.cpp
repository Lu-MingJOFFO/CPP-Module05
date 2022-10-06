/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:46:17 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/29 11:21:31 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): _target("NoTarget"), _signed(false), _gradeToSign(25), _gradeToExecute(5)
{
	std::cout << "PresidentialPardonForm constructor called without target" << std::endl;
	throw std::string("Error: PresidentialPardonForm cannot be instanciated without a target");
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): _target(target), _signed(false), _gradeToSign(25), _gradeToExecute(5)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src): _target(src._target), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = src;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	//std::cout << "Destructor called." << std::endl;
}

std::string PresidentialPardonForm::getName(void)
{
	return (_target);
}

bool PresidentialPardonForm::getSignedStatus(void)
{
	return (_signed);
}

int PresidentialPardonForm::getGradeToSign(void)
{
	return (_gradeToSign);
}

int PresidentialPardonForm::getGradeToExecute(void)
{
	return (_gradeToExecute);
}

void PresidentialPardonForm::beSigned(Bureaucrat & inst)
{
	std::cout << inst.getName() << " attempting to sign PresidentialPardonForm: ";
	if (inst.getGrade() <= _gradeToSign)
	{
		_signed = true;
		inst.signForm("PresidentialPardonForm", _signed);
	}
	else
	{
		inst.signForm("PresidentialPardonForm", _signed);
		throw PresidentialPardonForm::GradeTooLowException();
	}
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " attempting to execute PresidentialPardonForm: ";
	if (_signed == 1 && executor.getGrade() <= _gradeToExecute)
	{
		std::cout << _target << " has been pardonned by Zaphod Beeblebrox" << std::endl;

		std::cout << executor.getName() << " executed PresidentialPardonForm with target " << _target << std::endl;
	}
	else if (_signed == 0)
	{
		throw PresidentialPardonForm::FormNotSignedException();
	}
	else
		throw PresidentialPardonForm::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm & rhs)
{
	o << "Target = " << rhs.getName() << ". Signature Status = " << rhs.getSignedStatus() 
	<< ". Signing grade = " << rhs.getGradeToSign() << ". Executing grade = " << rhs.getGradeToExecute();
	return o;
}