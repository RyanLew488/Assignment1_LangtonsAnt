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

		int** gameBoard;
		
		menu(cont, random, bHeight, bWidth, turns);
		if (cont == 0) {
			gameLoop = false;
		}
		else {

			if (random = 0) {

			}
			Ant game(gameBoard, bHeight, bWidth, startX, startY);
		}
	}

	std::cin.get();
	
}