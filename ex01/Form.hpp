#ifndef FORM_HPP

# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:

		const std::string	name;
		bool				_signed;
		const short			signGrade;
		const short			executeGrade;

	public:

		Form(void);
		Form(const std::string &name, short signGrade, short executionGrade);
		Form(const Form &copy);
		~Form(void);

		Form	&operator=(Form const &copy);

		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		short				getSignGrade(void) const;
		short				getExecuteGrade(void) const;


		void				beSigned(Bureaucrat &bureaucrat);


		class GradeTooHighException : public std::exception {
		    public:
				const char* what() const throw() {
					return ("Grade too high");
				}
		};

		class GradeTooLowException : public std::exception {
		    public:
				const char* what() const throw() {
					return ("Grade too low");
				}
		};

};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
