/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:40:52 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/24 14:42:16 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
//#include <exception>

class	Bureaucrat
{
	public:
		Bureaucrat(void);
		Bureaucrat (std::string name, int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat & operator=(Bureaucrat const &rhs);
		~Bureaucrat(void);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
     			{
					return ("Error, grade cannot be a value below 1");
     			}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
     			{
					return ("Error, grade cannot be a value above 150");
     			}
		};
		std::string getName(void);
		int getGrade(void);
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(std::string str, bool sign);
		
	private:
		std::string const	_name;
		int					_grade;
		
};

std::ostream & operator<<(std::ostream & o, Bureaucrat & rhs);

#endif