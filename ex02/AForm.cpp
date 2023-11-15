#include "AForm.hpp"

void	checkGradeAForm(short grade) {
	if(1 > grade)
		throw AForm::GradeTooHighException();
	else if(grade > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(void): name("Default"), signed(false), signGrade(30), executeGrade(70) {
	checkGradeAForm(signGrade);
	checkGradeAForm(executeGrade);
}

AForm::AForm(const std::string &name, short signGrade, short executeGrade): name(name), signed(false), signGrade(signGrade), executeGrade(executeGrade) {
	checkGradeAForm(signGrade);
	checkGradeAForm(executeGrade);
}

AForm::~AForm(void) {

}

AForm::AForm(const AForm &copy): name(copy.name), signed(copy.signed), signGrade(copy.signGrade), executeGrade(copy.executeGrade) {

	*this = copy;
}

AForm	&AForm::operator=(const AForm &copy) {
	this->signed = copy.signed;
	return (*this);
}

const std::string	&AForm::getName(void) const {
	return (this->name);
}

bool	AForm::isSigned(void) const {
	return (this->signed);
}

short	AForm::getSignGrade(void) const {
	return (this->signGrade);
}

short	AForm::getExecuteGrade(void) const {
	return (this->executeGrade);
}

void	AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	this->signed = true;
	std::cout << "AForm " << this->name << " has been signed" << std::endl;
}

std::ostream &operator<<(std::ostream &o, AForm const &b)
{

	o << b.getName() <<" AForm\n" <<
		"signed: " << b.isSigned() << "\n" <<
		"signGrade: " << b.getSignGrade() << "\n" <<
		"executeGrade: " << b.getExecuteGrade() << "\n";

	return o;
}

