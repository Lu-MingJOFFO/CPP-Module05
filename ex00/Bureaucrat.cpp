/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:46:17 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/27 15:47:23 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("NoName")
{
	std::cout << "Constructor called without name and grade" << std::endl;
	throw std::string("Error: Bureaucrat cannot be instanciated without a grade");
}

Bureaucrat::Bureaucrat (std::string name, int grade): _name(name)
{
	std::cout << "Constructor called with name " << _name << " and attempted grade " << grade << std::endl;
	if (1 <= grade && grade <= 150)
		_grade = grade;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (150 < grade)
		throw Bureaucrat::GradeTooLowException();
		//throw std::string("Error: Bureaucrat's grade needs to be between 1 and 150!");
}

Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src._name)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_grade = rhs._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
	//std::cout << "Destructor called." << std::endl;
}

std::string Bureaucrat::getName(void)
{
	return (_name);
}

int Bureaucrat::getGrade(void)
{
	return (_grade);
}

void Bureaucrat::incrementGrade(void)
{
	std::cout << "Increment attempt: ";
	if (_grade >= 2)
	{
		_grade = _grade - 1;
		std::cout << "Successful, grade now equal to " << _grade << std::endl;
	}
	else
		throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade(void)
{
	std::cout << "Decrement attempt: ";
	if (_grade <= 149)
	{
		_grade = _grade + 1;
		std::cout << "Successful, grade now equal to " << _grade << std::endl;
	}
	else
		throw Bureaucrat::GradeTooLowException();
}

std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs)
{
	o << "Bureaucrat " << rhs.getName() << " successfully graded " << rhs.getGrade();
	return o;
}