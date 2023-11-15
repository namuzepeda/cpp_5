#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string &target): AForm("PresidentialPardonForm", 72, 45), target(target) {

}

PresidentialPardonForm::~PresidentialPardonForm() {

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): Form(copy), target(target) {
	*this = copy;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
	(void) copy;
	return (*this);
}

void    PresidentialPardonForm::execute( const Bureaucrat& executor ) const {
    if (!this->signed)
        throw Form::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute() ) {
        throw Form::GradeTooLowException();
    }
    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

