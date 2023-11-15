#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm("ShrubberyCreationForm", 145, 137), target(target) {

}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): Form(copy), target(target) {
	*this = copy;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
	(void) copy;
	return (*this);
}

void    ShrubberyCreationForm::execute( const Bureaucrat& executor ) const {
    if (!this->signed)
        throw Form::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute() ) {
        throw Form::GradeTooLowException();
    }

    std::ofstream file( this->getName() + "_shrubbery" );
    file << "       ###" << std::endl;
    file << "      #o###" << std::endl;
    file << "    #####o###" << std::endl;
    file << "   #o#\\#|#/###" << std::endl;
    file << "    ###\\|/#o#" << std::endl;
    file << "     # }|{  #" << std::endl;
    file << "		}|{" << std::endl;
    file.close();
}

