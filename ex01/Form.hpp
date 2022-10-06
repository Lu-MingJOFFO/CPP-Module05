/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:40:52 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/27 16:26:50 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class	Form
{
	public:
		Form(void);
		Form(std::string name, int gradeS, int gradeE);
		Form(Form const &src);
		Form & operator=(Form const &rhs);
		~Form(void);
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
     			{
					return ("Error, grade too high");
     			}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
     			{
					return ("Error, grade too low");
     			}
		};
		std::string getName(void);
		bool getSignedStatus(void);
		int getGradeToSign(void);
		int getGradeToExecute(void);
		void beSigned(Bureaucrat & inst);
		
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		
};

std::ostream & operator<<(std::ostream & o, Form & rhs);

#endif