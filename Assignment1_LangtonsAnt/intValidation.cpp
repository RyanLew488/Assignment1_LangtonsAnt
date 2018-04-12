#include <iostream>
#include <sstream>
#include <string>

int iValidation(std::string message) {
	bool valid = false;
	int validInteger = 0;
	std::string input = "";
	
	

	do {
		std::cout << message << std::endl;
		std::getline(std::cin, input);
		std::stringstream check(input);

		if (check >> validInteger)	{
			valid = true;
		}


	} while (valid == false);
	return validInteger;
}

int iRangeValidation(std::string message, int lowerBound, int upperBound) {
	bool valid = false;
	int validInteger = 0;
	std::string input = "";



	do {
		std::cout << message << std::endl;
		std::getline(std::cin, input);
		std::stringstream check(input);

		if (check >> validInteger) {
			if (validInteger < lowerBound || validInteger > upperBound) {

				std::cout << "The number you entered exceeded boundaries \n";
			}
			else {

				valid = true;
			}
		}


	} while (valid == false);
	return validInteger;
}