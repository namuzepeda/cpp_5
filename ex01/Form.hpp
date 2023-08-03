#ifndef FORM_HPP

# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Form
{
	private:

		const std::string	name;
		bool				_signed;
		const short			signGrade;
		const short			executeGrade;


	public:

		Form(const std::string &name, short grade);
		Form(Form const &copy);
		~Form(void);

		Form	&operator=(Form const &copy);

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

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
