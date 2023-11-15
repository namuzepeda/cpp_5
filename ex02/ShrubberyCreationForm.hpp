#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{

	private:

		std::string target;

	public:

		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &copy);

		void					execute( const Bureaucrat& executor ) const;

};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &rhs);

#endif
