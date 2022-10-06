/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:21:54 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/29 11:25:22 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{	
		ShrubberyCreationForm form("garden");
		std::cout << "ShrubberyCreationForm attributes: " << form << std::endl;
		
		Bureaucrat burA("BurA", 5);
		
		try
		{
			burA.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}
	
		Bureaucrat burB("BurB", 143);

		form.beSigned(burB);

		try
		{
			burB.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}
		
		form.beSigned(burA);
		burA.executeForm(form);
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	std::cout << std::endl;

	try
	{	
		RobotomyRequestForm form("Human");
		std::cout << "RobotomyRequestForm attributes: " << form << std::endl;
		
		Bureaucrat burA("BurA", 5);
		
		try
		{
			burA.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}
	
		Bureaucrat burB("BurB", 50);

		form.beSigned(burB);

		try
		{
			burB.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}
		
		form.beSigned(burA);
		burA.executeForm(form);
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	std::cout << std::endl;

	try
	{	
		PresidentialPardonForm form("Trillian");
		std::cout << "PresidentialPardonForm attributes: " << form << std::endl;
		
		Bureaucrat burA("BurA", 5);
		
		try
		{
			burA.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}
	
		Bureaucrat burB("BurB", 20);

		form.beSigned(burB);

		try
		{
			burB.executeForm(form);
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}
		
		form.beSigned(burA);
		burA.executeForm(form);
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	return 0;
}
	
	
		
		
	