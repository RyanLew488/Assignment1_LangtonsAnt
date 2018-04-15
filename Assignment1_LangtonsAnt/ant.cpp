#include <iostream>
#include "ant.hpp"

Ant::Ant() {
	createBoard(10,10);
	boardHeight = 10;
	boardWidth = 10;
	xPos = 1;
	yPos = 1;
	direction = 0;
}

Ant::Ant(int h, int w, int x, int y) {
	createBoard((h + 2), (w + 2));
	boardHeight = h;
	boardWidth = w;
	setStartPos(x, y);
	direction = 0;
}

void Ant::createBoard(int row, int col) {

	board = new int*[row];
	for (int i = 0; i < row; i++) {
		board[i] = new int[col];
	}
}

void Ant::fillBoard(int height, int width) {
	for (int row = 0; row < height + 1; row++) {

		for (int col = 0; col < width + 1 ; col++) {
			board[row][col] = 0;
		}
	}
}

void Ant::printBoard() {

	for (int i = 0; i < boardHeight + 1; i++) {
		for (int j = 0; j < boardWidth + 1; j++) {
			if (i == 0 || i == boardHeight) {
				std::cout << "_";
			}
			else if (j == 0 || j == boardWidth ) {
				std::cout << "|";
			}
			else if (i == yPos && j == xPos) {
				std::cout << "*";
			}
			else if (board[i][j] == 0) {
				std::cout << "0";
			}
			else {
				std::cout << "1";
			}
		}
		std::cout << std::endl;
	}
}


void Ant::setStartPos (int x, int y) {

	xPos = x;
	yPos = y;
}

void Ant::turn() {

	if (board[yPos][xPos] == 0) {

		direction++;
		if (direction > 3) {

			direction = 0;
		}
		
	}

	else {
		 
		direction--;
		if (direction < 0) {

			direction = 3;
		}
		
	}
}

void Ant::changeState() {

	if (board[yPos][xPos] == 0) {

		board[yPos][xPos] = 1;
	}

	else /*if (board[yPos][xPos] == 1)*/ {

		board[yPos][xPos] = 0;
	}
}

void Ant::moveForward() {
	
	switch (direction) {

	case 0 :

		if (yPos <= 1) {

			yPos == boardHeight;

		}
		else {

			yPos--;
		}
		break;

	case 1 :

		if (xPos >= boardWidth) {

			xPos = 1;
		}
		else {

			xPos++;
		}
		break;

	case 2 :

		if (yPos >= boardHeight) {

			yPos = 1;
		}
		else {

			yPos++;
		}
		break;

	case 3 :

		if (xPos == 1) {

			xPos <= boardWidth;
		}
		else {

			xPos--;
		}
		break;
	}
}

void Ant::deallocate() {

}
