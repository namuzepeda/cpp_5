#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
	private:

		const std::string	name;
		short				grade;

		void				setGrade(short grade);

	public:

		Bureaucrat(const std::string &name, short grade);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);

		Bureaucrat	&operator=(Bureaucrat const &copy);

		const std::string	&getName(void) const;
		short				getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);


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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
