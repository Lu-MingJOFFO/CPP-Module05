/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:21:54 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/22 20:01:49 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	// try
	// {
	// 	Bureaucrat inst;
	// 	std::cout << inst << std::endl;
	// }
	// catch(std::string const& chaine)
   	// {
    //    std::cout << chaine << std::endl;
   	// }
	
	try
	{	
		Bureaucrat inst("Bur", -2);
		std::cout << inst << std::endl;
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	try
	{	
		Bureaucrat inst("Bur", 154);
		std::cout << inst << std::endl;
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}
	
	try
	{	
		Bureaucrat inst("Bur", 3);
		std::cout << inst << std::endl;
		inst.incrementGrade();
		inst.incrementGrade();
		inst.incrementGrade();
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	try
	{	
		Bureaucrat inst("Bur", 149);
		std::cout << inst << std::endl;
		inst.decrementGrade();
		inst.decrementGrade();
		inst.decrementGrade();
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	return 0;
}
	
	
		
		
	