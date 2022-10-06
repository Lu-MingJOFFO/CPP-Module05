/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:40:52 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/28 18:06:25 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "Form.hpp"

class	ShrubberyCreationForm: public Form
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const &rhs);
		~ShrubberyCreationForm(void);
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
		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw()
     			{
					return ("Error, form not signed");
     			}
		};
		std::string getName(void);
		bool getSignedStatus(void);
		int getGradeToSign(void);
		int getGradeToExecute(void);
		void beSigned(Bureaucrat & inst);
		void execute(Bureaucrat const & executor) const;
		
	private:
		std::string const	_target;
		bool				_signed;
		int const			_gradeToSign;
		int const			_gradeToExecute;
		
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm & rhs);

#endif