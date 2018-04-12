#include <iostream>
#include "ant.hpp"
#include "intValidation.hpp"


int main() {

	int num = 0;
	std::string message = "Please enter a integer";
	num = iValidation(message);

	std::cout << "You entered: " << num << std::endl;

	std::string message2 = "Please enter a integer between 0 and 100";
	int num2 = iRangeValidation(message2, 0, 100);

	std::cout << "You entered: " << num2 << std::endl;
	

	std::cin.get();
	
}