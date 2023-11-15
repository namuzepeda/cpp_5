#include "Bureaucrat.hpp"

void	checkGrade(short grade) {
	if(1 > grade)
		throw Bureaucrat::GradeTooHighException();
	else if(grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(): name("Default"), grade(75) {
	checkGrade(grade);
}

Bureaucrat::Bureaucrat(const std::string &name, short grade): name(name), grade(grade) {
	checkGrade(grade);
}

Bureaucrat::~Bureaucrat(void) {

}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {

	*this = copy;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &copy) {
	this->name = copy.name;
	this->grade = copy.grade;
	return (*this);
}

short	Bureaucrat::getGrade(void) const {
	return (this->grade);
}

const std::string	&Bureaucrat::getName(void) const {
	return (this->name);
}

void	Bureaucrat::setGrade(short grade) {
	checkGrade(grade);
	this->grade = grade;
}

void	Bureaucrat::incrementGrade(void) {
	setGrade(this->grade - 1);
}

void	Bureaucrat::decrementGrade(void) {
	setGrade(this->grade + 1);
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &b)
{

	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";

	return o;
}

