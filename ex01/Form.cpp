#include "Form.hpp"

void	checkGradeForm(short grade) {
	if(1 > grade)
		throw Form::GradeTooHighException();
	else if(grade > 150)
		throw Form::GradeTooLowException();
}

Form::Form(void): name("Default"), signed(false), signGrade(30), executeGrade(70) {
	checkGradeForm(signGrade);
	checkGradeForm(executeGrade);
}

Form::Form(const std::string &name, short signGrade, short executeGrade): name(name), signed(false), signGrade(signGrade), executeGrade(executeGrade) {
	checkGradeForm(signGrade);
	checkGradeForm(executeGrade);
}

Form::~Form(void) {

}

Form::Form(const Form &copy): name(copy.name), signed(copy.signed), signGrade(copy.signGrade), executeGrade(copy.executeGrade) {

	*this = copy;
}

Form	&Form::operator=(const Form &copy) {
	this->signed = copy.signed;
	return (*this);
}

const std::string	&Form::getName(void) const {
	return (this->name);
}

bool	Form::isSigned(void) const {
	return (this->signed);
}

short	Form::getSignGrade(void) const {
	return (this->signGrade);
}

short	Form::getExecuteGrade(void) const {
	return (this->executeGrade);
}

void	Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw Form::GradeTooLowException();
	this->signed = true;
	std::cout << "Form " << this->name << " has been signed" << std::endl;
}

std::ostream &operator<<(std::ostream &o, Form const &b)
{

	o << b.getName() <<" Form\n" <<
		"signed: " << b.isSigned() << "\n" <<
		"signGrade: " << b.getSignGrade() << "\n" <<
		"executeGrade: " << b.getExecuteGrade() << "\n";

	return o;
}

