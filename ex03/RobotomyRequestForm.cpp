/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:46:17 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/29 17:35:25 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): _target("NoTarget"), _signed(false), _gradeToSign(72), _gradeToExecute(45)
{
	std::cout << "RobotomyRequestForm constructor called without target" << std::endl;
	throw std::string("Error: RobotomyRequestForm cannot be instanciated without a target");
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): _target(target), _signed(false), _gradeToSign(72), _gradeToExecute(45)
{
	std::cout << "RobotomyRequestForm constructor called with target " << _target << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): _target(src._target), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = src;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

std::string RobotomyRequestForm::getName(void)
{
	return (_target);
}

bool RobotomyRequestForm::getSignedStatus(void)
{
	return (_signed);
}

int RobotomyRequestForm::getGradeToSign(void)
{
	return (_gradeToSign);
}

int RobotomyRequestForm::getGradeToExecute(void)
{
	return (_gradeToExecute);
}

void RobotomyRequestForm::beSigned(Bureaucrat & inst)
{
	std::cout << inst.getName() << " attempting to sign RobotomyRequestForm: ";
	if (inst.getGrade() <= _gradeToSign)
	{
		_signed = true;
		inst.signForm("RobotomyRequestForm", _signed);
	}
	else
	{
		inst.signForm("RobotomyRequestForm", _signed);
		throw RobotomyRequestForm::GradeTooLowException();
	}
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " attempting to execute RobotomyRequestForm: ";
	if (_signed == 1 && executor.getGrade() <= _gradeToExecute)
	{
		std::cout << "BBBBBRRRRRRRRRRRRRRRRRRRRRRRRRR: ";
		srand(time(NULL));
		if (rand() % 2)
			std::cout << _target << " was robotomized" << std::endl;
		else
			std::cout << _target << " robotomization failed" << std::endl;
		std::cout << executor.getName() << " executed RobotomyRequestForm with target " << _target << std::endl;
	}
	else if (_signed == 0)
	{
		throw RobotomyRequestForm::FormNotSignedException();
	}
	else
		throw RobotomyRequestForm::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm & rhs)
{
	o << "Target = " << rhs.getName() << ". Signature Status = " << rhs.getSignedStatus() 
	<< ". Signing grade = " << rhs.getGradeToSign() << ". Executing grade = " << rhs.getGradeToExecute();
	return o;
}