#include <iostream>
#include "ant.hpp"

Ant::Ant() {
	board = createBoard(10, 10);
}

Ant::Ant(int** boardPtr, int h, int w, int x, int y) {
	board = boardPtr;
	boardHeight = h;
	boardWidth = w;
	xPos = x;
	yPos = y;
	direction = 0;
}

int** Ant::createBoard(int height, int width) {

	board = new int*[height];
	for (int i = 0; i < width; i++) {
		board[i] = new int[width];
	}
	return board;
}

void fillBoard(int** board, int height, int width) {
	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {
			board[i][j] = 0;
		}
	}
}

void Ant::printBoard() {
	std::cout << "Printing the board";
	for (int i = 0; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}
void Ant::setStartPos (int x, int y){

	xPos = x;
	yPos = y;
}

void Ant::turn() {
	if (squareState == 0) {

		if (direction >= 3) {

			direction = 0;
		}
		else {

			direction++;
		}
	}
	else {
		
		if (direction <= 0) {

			direction = 3;
		}
		else {

			direction--;
		}
	}
}

void Ant::changeState() {
	if (squareState == 0) {

		squareState = 1;
	}
	else {

		squareState = 0;
	}
}

void Ant::moveForward() {

	switch (direction) {

	case 0 :
		if (yPos == 1) {

			yPos == boardHeight;
		}
		else {

			yPos--;
		}
		break;

	case 1 :

		if (xPos == boardWidth) {

			xPos = 1;
		}
		else {
			xPos++;
		}
		break;

	case 2 :

		if (yPos == boardHeight) {
			yPos = 1;
		}
		else {
			yPos++;
		}
		break;

	case 3 :

		if (xPos == 1) {
			xPos == boardWidth;
		}
		else {
			xPos--;
		}
		break;
	}
}

