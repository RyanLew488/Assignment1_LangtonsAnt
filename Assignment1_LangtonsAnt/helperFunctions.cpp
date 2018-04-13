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

void menu(int& choice, int& randomStart, int& h, int& w, int& turns) {

	std::cout << "Would you like to play a game of Langton's ant? \n"
			  << "1 for yes \n0 for no \n";

	std::string m = "Please enter your choice";

	int gameChoice = iRangeValidation(m, 0, 1);
	choice = gameChoice;

	std::cout << "How tall would you like the board?\n";
	m = "Please enter a positive integer < 5 and > 100";
	h = iRangeValidation(m, 5, 100);

	std::cout << "How wide would you like the board?\n";
	w = iRangeValidation(m, 5, 100);

	std::cout << "Would you like to specify a starting point?\n"
			  << "0 for player choice\n1 for random";

	int startChoice = iRangeValidation(m, 0, 1);
	randomStart = startChoice;

	m = "Please select between 0 and 50,000 turns";
	int numTurns = iRangeValidation(m, 10, 50000);
	turns = numTurns;
}