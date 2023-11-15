#ifndef AFORM_HPP

# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:

		const std::string	name;
		bool				signed;
		const short			signGrade;
		const short			executeGrade;

	public:

		AForm(void);
		AForm(const std::string &name, short signGrade, short executionGrade);
		AForm(const AForm &copy);
		virtual ~AForm(void);

		AForm	&operator=(AForm const &copy);

		const std::string	&getName(void) const;
		bool				isSigned(void) const;
		short				getSignGrade(void) const;
		short				getExecuteGrade(void) const;


		void				beSigned(Bureaucrat &bureaucrat);

		virtual void		execute(Bureaucrat const & executor) = 0;


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

		class NotSignedException : public std::exception {
		    public:
				const char* what() const throw() {
					return ("Form not signed");
				}
		};

};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif
