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
	createBoard(h, w);
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
	for (int row = 0; row < height; row++) {

		for (int col = 0; col < width; col++) {
			board[row][col] = 0;
		}
	}
}

void Ant::printBoard() {
	
	for (int i = 0; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			if (i == yPos && j == xPos) {
				std::cout << "*";
			}
			else if (board[i][j] == 0) {
				std::cout << " ";
			}
			else {
				std::cout << "#";
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

	else {

		board[yPos][xPos] = 0;
	}
}

void Ant::moveForward() {
	
	switch (direction) {

	//Moving to the top (North)
	case 0 :

		if (yPos == 0) {

			yPos = boardHeight - 1;

		}
		else {

			yPos--;
		}
		break;

	//Moving to the right (East)
	case 1 :

		if (xPos == boardWidth - 1) {

			xPos = 0;
		}
		else {

			xPos++;
		}
		break;
	
	//Moving to the bottom (South)
	case 2 :

		if (yPos == boardHeight - 1) {

			yPos = 0;
		}
		else {

			yPos++;
		}
		break;

	//Moving to the left (West)
	case 3 :

		if (xPos == 0) {

			xPos = boardWidth - 1;
		}
		else {

			xPos--;
		}
		break;
	}
}

void Ant::deallocate() {
	for (int row = 0; row < boardWidth; row++) {
		delete[]board[row];
	}
	delete[]board;
}
