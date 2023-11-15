#ifndef ROBOTOMYREQUESTFORM_HPP

# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{

	private:

		std::string target;

	public:

		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		~RobotomyRequestForm(void);

		RobotomyRequestForm	&operator=(RobotomyRequestForm const &copy);

		void					execute( const Bureaucrat& executor ) const;

};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &rhs);

#endif
