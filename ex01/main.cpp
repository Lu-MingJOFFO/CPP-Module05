/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:21:54 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/27 16:31:07 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try
	{	
		Form formA("FormA", -2, 0);
		std::cout << "Form created with attributes: " << formA << std::endl;
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}
	
	try
	{	
		Form formB("FormB", 20, 10);
		std::cout << "Form created with attributes: " << formB << std::endl;
		
		Bureaucrat burA("BurA", 30);
		try
		{
			formB.beSigned(burA);
			std::cout << "FormB attributes: " << formB << std::endl;
		}
		catch(std::exception & e)
   		{
       		std::cout << e.what() << std::endl;
   		}
	
		Bureaucrat burB("BurB", 4);
		formB.beSigned(burB);
		std::cout << "FormB attributes: " << formB << std::endl;
	}
	catch(std::exception & e)
   	{
       std::cout << e.what() << std::endl;
   	}

	return 0;
}
	
	
		
		
	