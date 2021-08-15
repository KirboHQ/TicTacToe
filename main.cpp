#include <iostream>
#include <string>
#include <time.h>
#include <unistd.h>

using namespace std;

int board[9] = {0}, p1move, p2move, turn = 1, i, line, player;
bool gameEnded = false, turnEnded = false;

string p1[7];
string p2[7];
string empty[7];

int checkWL() {
	
	// P1 WINS
	
	if (board[0] == 1 && board[1] == 1 && board[2] == 1 ||
	    board[3] == 1 && board[4] == 1 && board[5] == 1 ||
	    board[6] == 1 && board[7] == 1 && board[8] == 1 ||
	    board[0] == 1 && board[3] == 1 && board[6] == 1 ||
	    board[1] == 1 && board[4] == 1 && board[7] == 1 ||
	    board[2] == 1 && board[5] == 1 && board[8] == 1 ||
	    board[0] == 1 && board[4] == 1 && board[8] == 1 ||
	    board[2] == 1 && board[4] == 1 && board[6] == 1) {
		
		gameEnded = true;
		cout << "P1 wins!" << endl;
	}
	
	// P2 WINS

	else if (board[0] == 2 && board[1] == 2 && board[2] == 2 ||
		 board[3] == 2 && board[4] == 2 && board[5] == 2 ||
		 board[6] == 2 && board[7] == 2 && board[8] == 2 ||
		 board[0] == 2 && board[3] == 2 && board[6] == 2 ||
		 board[1] == 2 && board[4] == 2 && board[7] == 2 ||
		 board[2] == 2 && board[5] == 2 && board[8] == 2 ||
	 	 board[0] == 2 && board[4] == 2 && board[8] == 2 ||
		 board[2] == 2 && board[4] == 2 && board[6] == 2) {
		
		gameEnded = true;
		cout << "P2 wins!" << endl;
	}
	
	// DRAW
	
	else if (board[0] != 0 &&
		 board[1] != 0 &&
		 board[2] != 0 &&
		 board[3] != 0 &&
		 board[4] != 0 &&
		 board[5] != 0 &&
		 board[6] != 0 &&
		 board[7] != 0 &&
		 board[8] != 0) {
		
		gameEnded = true;
		cout << "Draw!" << endl;
	}
}

int writeBoard() {
	
	cout << "\n";
	
	for (line = 0; line < 7; line++) {
	
		for (i = 0; i < 3; i++) {
				
			if (board[i] == 0) {
				
				cout << empty[line];	
			}
			else if (board[i] == 1) {
				
				cout << p1[line];
			}
			else if (board[i] == 2) {
				
				cout << p2[line];
			}
			
			if (i != 2) {
				
				cout << "=";
			}
		}
		cout << "\n";
	}
	cout << "=============================\n";
	
	for (line = 0; line < 7; line++) {
	
		for (i = 3; i < 6; i++) {
				
			if (board[i] == 0) {
				
				cout << empty[line];	
			}
			else if (board[i] == 1) {
				
				cout << p1[line];
			}
			else if (board[i] == 2) {
				
				cout << p2[line];
			}
			
			if (i != 5) {
				
				cout << "=";
			}
		}
		cout << "\n";
	}
	cout << "=============================\n";
	
	for (line = 0; line < 7; line++) {

		for (i = 6; i < 9; i++) {
				
			switch (board[i]) {

				case 0:
					cout << empty[line];
				break;

				case 1:
					cout << p1[line];
				break;

				case 2:
					cout << p2[line];
				break;
			}
			
			if (i != 8) {
				
				cout << "=";
			}
		}
		cout << "\n";
	}
	
	cout << "\n";
}

int main () {
	
	p1[0]	 = "         ";
	p1[1]	 = "  XX XX  ";
	p1[2]	 = "  XX XX  ";
	p1[3]	 = "   XXX   ";
	p1[4]	 = "  XX XX  ";
	p1[5]	 = "  XX XX  ";
	p1[6]	 = "         ";
	
	p2[0]	 = "         ";
	p2[1]	 = "   OOO   ";
	p2[2]	 = "  OO OO  ";
	p2[3]	 = "  O   O  ";
	p2[4]	 = "  OO OO  ";
	p2[5]	 = "   OOO   ";
	p2[6]	 = "         ";
	
	empty[0] = "         ";
	empty[1] = "         ";
	empty[2] = "         ";
	empty[3] = "         ";
	empty[4] = "         ";
	empty[5] = "         ";
	empty[6] = "         ";

	do {
		cout << "Choose who you want to play against:\n1)Player\n2)CPU\n>> ";
		cin >> player;

		if (player != 1 && player != 2) {

			cout << "ERROR: The choice must be 1 or 2." << endl;
		}

	} while (player	!= 1 && player != 2);

	while (gameEnded == false) {
		
		writeBoard();
		checkWL();
		
		if (gameEnded == false) {
			
			turnEnded = false;
		}
		
		while (turnEnded == false) {
			
			switch (turn) {

				case 1:
					cout << "(P1) Where do you want do draw the cross? (1-9): ";
					cin >> p1move;
					p1move--;
					
					if (board[p1move] != 0 || p1move > 9) {
						
						cout << "(P1) The slot is occupied, choose another one." << endl;
					}
					else {
						
						board[p1move] = 1;
						turnEnded = true;
						turn = 2;
					}
				break;
				case 2:
					cout << "(P2) Where do you want to draw the circle? (1-9): ";
					sleep(2);

					switch (player) {

						case 1:
							cin >> p2move;
							p2move--;
									
							if (board[p2move] != 0 || p2move > 9) {
								
								cout << "(P2) The slot is occupied, choose another one." << endl;
							}
							else {
								
								board[p2move] = 2;
								turnEnded = true;
								turn = 1;
							}
						break;
						case 2:
							srand(time(NULL));

							do {
								
								p2move = rand()% 9;

							} while (board[p2move] != 0);

							cout << p2move + 1 << endl;
							board[p2move] = 2;
							turnEnded = true;
							turn = 1;
						break;
					}
				break;
			}
		}
	}

	cout << "\n";
	system ("PAUSE");
}
