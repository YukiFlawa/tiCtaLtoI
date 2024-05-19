#include<iostream>
#include<math.h>
#include<string>

using namespace std;

class canvas {
protected:
	std::string playBoard[3][3] = {};
	int rows = 0;
	int columns = 0;

public:
		void showBoard() {
			for (rows = 0; rows < 3; rows++) {
				for (columns = 0; columns < 3; columns++) {
					cout << playBoard[rows][columns];
				}
				cout << endl;
			}
		}

		void resetBoard() {
			for (rows = 0; rows < 3; rows++) {
				for (columns = 0; columns < 3; columns++) {
					playBoard[rows][columns] = "[]";
				}
			}
		}
};

class player : public canvas{
public:
	int currentMove[2] = {}; 
	std::string playerPiece;
	int playerid = 1;
	int direction[2] = {};
	std::string currentPiece;
	bool isplaying = true;

	void moveChoice() {
		cout << endl << "=========================" << endl;
		cout << "Enter Coordinate: "; cin >> currentMove[0] >> currentMove[1];
		currentMove[0]--;
		currentMove[1]--;
	}
	void resetChoice() {
		currentMove[0] = {};
		currentMove[1] = {};
	}
	void setPlayerPiece() {
		// Choose player piece
		if (playerid == 1) {
			playerPiece = "X ";
		}
		else if (playerid == -1) {
			playerPiece = "O ";
		}
		// Place Player and show board
		if (playBoard[currentMove[0]][currentMove[1]] == "[]") {

			playBoard[currentMove[0]][currentMove[1]] = playerPiece;
			showBoard();
			playerid *= -1;
		}
		else {
			cout << "Cannot place on already existing piece!" << endl;
		}
		winCondition();
	}
	void winCondition() {
		// Check if piece can win Horizontally
		currentPiece = playBoard[0][0];
		if (currentPiece != "[]") {
			if (playBoard[0][1] == currentPiece) {
				if (playBoard[0][2] == currentPiece) {
					// Win Condition 1;
					cout << currentPiece << " Wins the game";
					isplaying = false;
				}
			}
		}
		currentPiece = playBoard[1][0];
		if (currentPiece != "[]") {
			if (playBoard[1][1] == currentPiece) {
				if (playBoard[1][2] == currentPiece) {
					// Win Condition 2;
					cout << currentPiece << " Wins the game";
					isplaying = false;
				}
			}
		}
		currentPiece = playBoard[2][0];
		if (currentPiece != "[]") {
			if (playBoard[2][1] == currentPiece) {
				if (playBoard[2][2] == currentPiece) {
					// Win Condition 3;
					cout << currentPiece << " Wins the game";
					isplaying = false;
				}
			}
		}
		// Check if piece can win Vertically
		currentPiece = playBoard[0][0];
		if (currentPiece != "[]") {
			if (playBoard[1][0] == currentPiece) {
				if (playBoard[2][0] == currentPiece) {
					// Win Condition 4;
					cout << currentPiece << " Wins the game";
					isplaying = false;
				}
			}
		}
		currentPiece = playBoard[0][1];
		if (currentPiece != "[]") {
			if (playBoard[1][1] == currentPiece) {
				if (playBoard[2][1] == currentPiece) {
					// Win Condition 5;
					cout << currentPiece << " Wins the game";
					isplaying = false;
				}
			}
		}
		currentPiece = playBoard[0][2];
		if (currentPiece != "[]") {
			if (playBoard[1][2] == currentPiece) {
				if (playBoard[2][2] == currentPiece) {
					// Win Condition 6;
					cout << currentPiece << " Wins the game";
					isplaying = false;
				}
			}
		}
		// Check if piece can win Diagonally
		currentPiece = playBoard[0][0];
		if (currentPiece != "[]") {
			if (playBoard[1][1] == currentPiece) {
				if (playBoard[2][2] == currentPiece) {
					// Win Condition 7;
					cout << currentPiece << " Wins the game";
					isplaying = false;
				}
			}
		}
		currentPiece = playBoard[2][2];
		if (currentPiece != "[]") {
			if (playBoard[1][1] == currentPiece) {
				if (playBoard[0][0] == currentPiece) {
					// Win Condition 8;
					cout << currentPiece << " Wins the game";
					isplaying = false;
				}
			}
		}
		int drawCount = 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (playBoard[i][j] == "[]") {
					drawCount++;
				}
			}
		}

		if (drawCount == 0 && isplaying) {
			cout << "Both Sides have drawn the match";
			isplaying = false;
		}
	}
};

int main() {
	player p1;
	std::string pieceWon = "[]";

	p1.resetBoard();
	p1.showBoard();
	
	int maxRows = 3;
	int maxColumns = 3;

	bool isPlaying = true;

	while (p1.isplaying){
		if (p1.currentMove[0] > maxRows && p1.currentMove[1] > maxColumns || p1.currentMove[0] < 0 && p1.currentMove[1] < 0 ) {
			cout << "All coordinates out of range!";
			p1.resetChoice();
			p1.moveChoice();
		}
		else if (p1.currentMove[0] > maxRows || p1.currentMove[0] < 0) {
			cout << "Row Coordinate out of range!";
			p1.resetChoice();
			p1.moveChoice();
		}
		else if (p1.currentMove[1] > maxColumns || p1.currentMove[1] < 0) {
			cout << "Column Coordinate out of range!";
			p1.resetChoice();
			p1.moveChoice();
		}
		else {
			// Play 
			p1.resetChoice();
			p1.moveChoice();
			p1.setPlayerPiece();
		}
	}
	return 0;
}