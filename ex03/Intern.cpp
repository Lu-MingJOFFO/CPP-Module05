/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:46:17 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/29 17:35:44 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(Intern const &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern & Intern::operator=(Intern const &rhs)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)rhs;
	return *this;
}

Intern::~Intern(void)
{
	// std::cout << "Intern destructor called." << std::endl;
}

Form* Intern::makeForm(std::string name, std::string target)
{
	std::string tab[4] = {"shrubbery creation", "robotomy request", "presidential pardon", "no form"};

	for (int i = 0; i < 4; i++)
	{
		if (name == tab[i] || i == 3)
		{
			switch (i) 
			{
				case 0 :
					std::cout << "Intern creates " << name << " form" << std::endl;
					return (new ShrubberyCreationForm(target));
					break;
				case 1 :
					std::cout << "Intern creates " << name << " form" << std::endl;
					return (new RobotomyRequestForm(target));
					break;
				case 2 :
					std::cout << "Intern creates " << name << " form" << std::endl;
					return (new PresidentialPardonForm(target));
				case 3 : 
					std::cout << "Error: the form " << name << " doesm't exist" << std::endl;
					return (0);
					break;
			}
		}
	}

	return (0);
}
