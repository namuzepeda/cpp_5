#include "Form.hpp"

void	checkGrade(short grade) {
	if(1 > grade)
		throw Form::GradeTooHighException();
	else if(grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string &name, short grade): name(name), _signed(false) {
	checkGrade(grade);
}

Form::~Form(void) {

}

Form::Form(const Form &copy) {

	*this = copy;
}

Form	&Form::operator=(const Form &copy) {
	this->grade = copy.grade;
	return (*this);
}

short	Form::getGrade(void) const {
	return (this->grade);
}

const std::string	&Form::getName(void) const {
	return (this->name);
}

void	Form::setGrade(short grade) {
	checkGrade(grade);
	this->grade = grade;
}

void	Form::incrementGrade(void) {
	setGrade(this->grade - 1);
}

void	Form::decrementGrade(void) {
	setGrade(this->grade + 1);
}

std::ostream &operator<<(std::ostream &o, Form const &b)
{

	o << b.getName() << ", Form grade " << b.getGrade() << ".";

	return o;
}

