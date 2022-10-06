/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:46:17 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/28 18:11:44 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(void): _name("NoName"), _signed(false), _gradeToSign(0), _gradeToExecute(0)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::Form(std::string name, int gradeS, int gradeE): _name(name), _signed(false), _gradeToSign(gradeS), _gradeToExecute(gradeE)
{
	std::cout << "Form constructor called with name " << _name << ", with signing grade " << gradeS << " and executing grade " << gradeE << std::endl;
	if (gradeS < 1 || gradeE < 1)
		throw Form::GradeTooHighException();
	if (150 < gradeS || 150 < gradeS)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = src;
}

Form & Form::operator=(Form const &rhs)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

Form::~Form(void)
{
	//std::cout << "Destructor called." << std::endl;
}

std::string Form::getName(void) const
{
	return (_name);
}

bool Form::getSignedStatus(void)
{
	return (_signed);
}

int Form::getGradeToSign(void)
{
	return (_gradeToSign);
}

int Form::getGradeToExecute(void)
{
	return (_gradeToExecute);
}

void Form::beSigned(Bureaucrat & inst)
{
	std::cout << _name << " attempting to be signed by " << inst.getName() << std::endl;
	if (inst.getGrade() <= _gradeToSign)
	{
		_signed = true;
		inst.signForm(_name, _signed);
	}
	else
	{
		inst.signForm(_name, _signed);
		throw Form::GradeTooLowException();
	}
}

void Form::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " attempting to execute form " << _name << std::endl;
}

std::ostream & operator<<(std::ostream & o, Form & rhs)
{
	o << "Name = " << rhs.getName() << ". Signature Status = " << rhs.getSignedStatus() 
	<< ". Signing grade = " << rhs.getGradeToSign() << ". Executing grade = " << rhs.getGradeToExecute();
	return o;
}