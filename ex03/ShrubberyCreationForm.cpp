/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:46:17 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/29 17:35:37 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): _target("NoTarget"), _signed(false), _gradeToSign(145), _gradeToExecute(137)
{
	std::cout << "ShrubberyCreationForm constructor called without target" << std::endl;
	throw std::string("Error: ShrubberyCreationForm cannot be instanciated without a target");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): _target(target), _signed(false), _gradeToSign(145), _gradeToExecute(137)
{
	std::cout << "ShrubberyCreationForm constructor called with target " << _target << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src): _target(src._target), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = src;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	// std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

std::string ShrubberyCreationForm::getName(void)
{
	return (_target);
}

bool ShrubberyCreationForm::getSignedStatus(void)
{
	return (_signed);
}

int ShrubberyCreationForm::getGradeToSign(void)
{
	return (_gradeToSign);
}

int ShrubberyCreationForm::getGradeToExecute(void)
{
	return (_gradeToExecute);
}

void ShrubberyCreationForm::beSigned(Bureaucrat & inst)
{
	std::cout << inst.getName() << " attempting to sign ShrubberyCreationForm: ";
	if (inst.getGrade() <= _gradeToSign)
	{
		_signed = true;
		inst.signForm("ShrubberyCreationForm", _signed);
	}
	else
	{
		inst.signForm("ShrubberyCreationForm", _signed);
		throw ShrubberyCreationForm::GradeTooLowException();
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	std::cout << executor.getName() << " attempting to execute ShrubberyCreationForm: ";
	if (_signed == 1 && executor.getGrade() <= _gradeToExecute)
	{
		std::string filename(_target + "_shrubbery");
		std::ofstream file(filename.c_str());

		file << "                 # #### ####			" << std::endl;
        file << "               ### \\/#|### |/####		" << std::endl;
        file << "              ##\\/#/ \\||/##/_/##/_#	" << std::endl;
        file << "            ###  \\/###|/ \\/ # ###	" << std::endl;
        file << "          ##_\\_#\\_\\## | #/###_/_####" << std::endl;
        file << "         ## #### # \\ #| /  #### ##/##	" << std::endl;
        file << "          __#_--###`  |{,###---###-~	" << std::endl;
        file << "                    \\ }{				" << std::endl;
        file << "                     }}{				" << std::endl;
        file << "                     }}{				" << std::endl;
        file << "                     {{}				" << std::endl;
        file << "               , -=-~{ .-^- _			" << std::endl;
        file << "                     `}				" << std::endl;
        file << "                      {				" << std::endl;

		std::cout << executor.getName() << " executed ShrubberyCreationForm with target " << _target << std::endl;
	}
	else if (_signed == 0)
	{
		throw ShrubberyCreationForm::FormNotSignedException();
	}
	else
		throw ShrubberyCreationForm::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm & rhs)
{
	o << "Target = " << rhs.getName() << ". Signature Status = " << rhs.getSignedStatus() 
	<< ". Signing grade = " << rhs.getGradeToSign() << ". Executing grade = " << rhs.getGradeToExecute();
	return o;
}