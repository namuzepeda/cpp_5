#include "AForm.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	try {
		Bureaucrat b1("b1", 15);
		Form form("TEST", 20, 30);
		while(b1.getGrade() != 1) {
			b1.signForm(form);
			std::cout << b1 << std::endl;
			b1.incrementGrade();
		}
		while(b1.getGrade() != 151) {
			b1.signForm(form);
			std::cout << b1 << std::endl;
			b1.decrementGrade();
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

