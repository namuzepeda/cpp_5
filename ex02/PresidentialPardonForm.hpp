#ifndef PRESIDENTIALPARDONFORM_HPP

# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{

	private:

		std::string target;

	public:

		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		~PresidentialPardonForm(void);

		PresidentialPardonForm	&operator=(PresidentialPardonForm const &copy);

		void					execute( const Bureaucrat& executor ) const;

};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &rhs);

#endif
