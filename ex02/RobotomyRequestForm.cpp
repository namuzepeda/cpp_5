#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm("RobotomyRequestForm", 72, 45), target(target) {

}

RobotomyRequestForm::~RobotomyRequestForm() {

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): Form(copy), target(target) {
	*this = copy;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
	(void) copy;
	return (*this);
}

void    RobotomyRequestForm::execute( const Bureaucrat& executor ) const {
    if (!this->signed)
        throw Form::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute() ) {
        throw Form::GradeTooLowException();
    }

    if (rand() & 1) {
        std::cout << "Bzzzz... " << _target << " has been robotomized!" << std::endl;
    } else {
        std::cout << "Robotomization for " << getTarget() << " failed !" << std::endl;
    }
}

