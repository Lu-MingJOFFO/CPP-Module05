/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljoffo <ljoffo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:40:52 by ljoffo            #+#    #+#             */
/*   Updated: 2022/07/29 11:02:36 by ljoffo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class	PresidentialPardonForm: public Form
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm & operator=(PresidentialPardonForm const &rhs);
		~PresidentialPardonForm(void);
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

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm & rhs);

#endif