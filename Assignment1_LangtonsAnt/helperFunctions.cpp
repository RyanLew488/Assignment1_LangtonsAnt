#include <iostream>
#include <sstream>
#include <string>

int iValid(std::string message) {
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

int iRangeValid(std::string message, int lowerBound, int upperBound) {
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

	int gameChoice = iRangeValid(m, 0, 1);
	choice = gameChoice;

	if (gameChoice == 1) {

		std::cout << "How tall would you like the board?\n";
		m = "Please enter a positive integer < 5 and > 100";
		h = iRangeValid(m, 5, 100);

		std::cout << "How wide would you like the board?\n";
		w = iRangeValid(m, 5, 100);

		std::cout << "Would you like to specify a starting point?\n"
			<< "0 for no (random start)\n1 for yes";

		int startChoice = iRangeValid(m, 0, 1);
		randomStart = startChoice;

		m = "Please select between 0 and 50,000 turns";
		int numTurns = iRangeValid(m, 10, 50000);
		turns = numTurns;
	}
	else {
		return;
	}
}

void mainMenu(int& play) {

}