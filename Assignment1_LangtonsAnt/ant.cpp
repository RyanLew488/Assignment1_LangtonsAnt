#include "ant.hpp"


void Ant::turn() {
	if (squareState == 0) {

		if (direction >= 3) {
			direction = 0;
		}
		else {
			direction++
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

	case: 0
		if (yPos == 1) {
			yPos == boardHeight;
		}
		else {
			yPos--;
		}
		break;

	case: 1
		if (xPos == boardWidth) {
			xPos = 1;
		}
		else {
			xPos++;
		}
		break;

	case: 2
		if (yPos == boardHeight) {
			yPos = 1;
		}
		else {
			yPos++
		}
		break;
	case 3:
		if (xPos == 1) {
			xPos == boardWidth;
		}
		else {
			xPos--;
		}
		break;
	}
}

