#include "Bureaucrat.hpp"

int	main(void)
{
	try {
		Bureaucrat b1("b1", 15);
		while(b1.getGrade() != 1) {
			std::cout << b1 << std::endl;
			b1.incrementGrade();
		}
		while(b1.getGrade() != 151) {
			std::cout << b1 << std::endl;
			b1.decrementGrade();
		}
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

