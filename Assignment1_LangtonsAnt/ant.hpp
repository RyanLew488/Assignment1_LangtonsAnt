#ifndef ANT_HPP
#define ANT_HPP

class Ant {
private:
	int direction;
	int xPos;
	int yPos;
	int boardHeight;
	int boardWidth;
	int** board;
	int squareState;

public:
	Ant();
	Ant(int** boardPtr, int h, int w, int x, int y);
	void menu();
	void setStartPos(int x, int y);
	int** createBoard(int height, int width);
	void fillBoard();
	void turn();
	void changeState();
	void moveForward();
	void printBoard();
	void deallocate();
};
#endif
