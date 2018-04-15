#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ant.hpp"
#include "helperFunctions.hpp"


int main() {

	bool gameLoop = true;

	while (gameLoop) {

		int cont = 0;
		int random = 0;
		int turns = 0;
		int bHeight = 0;
		int bWidth = 0;
		int startX = 1, startY = 1;

		menu(cont, random, bHeight, bWidth, turns);
		if (cont == 0) {
			gameLoop = false;
		}
		else {

			if (random == 0) {
				std::srand(time(0));

				startY = std::rand() % bHeight;
				startX = std::rand() % bWidth;

				

			}
			else {

				startX = iRangeValid("Please select your starting X position: ", 1, bWidth);
				startY = iRangeValid("Please select your starting Y position: ", 1, bHeight);
			}

			Ant game(bHeight, bWidth, startX, startY);
			
			game.fillBoard(bHeight, bWidth);
			game.printBoard();
			for (int c = 0; c < turns; c++) {
				
				game.turn();
				game.changeState();
				game.moveForward();
				game.printBoard();
			}
		}
	}
	std::cin.get();
	return 0;
}