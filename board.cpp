/*
Author: nickdsullivan@gmail.com
This class will define the board object.  It will place the pieces and check if the move is valid.
*/


#include "board.h"
#include<iostream>
#include<vector>
using namespace std;
Board::Board(){
	//Init the new Board
	board = new int*[SIDE_LENGTH];
	for (int i = 0; i < SIDE_LENGTH; i ++){
		board[i] = new int[SIDE_LENGTH];
	}
	board[4][4] = 1;
	board[4][3] = 2;
	board[3][3] = 1;
	board[3][4] = 2;
	

	
}
Board::~Board(){
	for (int i = 0; i < SIDE_LENGTH; i ++){
		delete [] board[i];
	}
	delete board;
}

void Board::restart(){
	for (int i = 0; i < SIDE_LENGTH; i ++){
		for (int j = 0; j < SIDE_LENGTH; j ++){
			board[i][j] = 0;
		}
	}
}
//This displays the board with x and os
void Board::display(){
	for (int i = 0; i < SIDE_LENGTH; i ++){
		for (int j = 0; j < SIDE_LENGTH; j ++){
			if (board[i][j] == 1){
				cout<< "[O]"<< " ";
			}
			else if (board[i][j] == 2){
				cout<< "[X]" << " ";
			}
			else {
				cout << "[ ]"<<" ";
			}
			
		}
		cout << endl;
	}
}


//Of course this the next method can be wrapped up into for loops.

//Also there is likely a cool algorthm to find the valid moves easier
//This brute forces finding allowed moves.  
void Board::returnValidMoves(vector<int*>& moves, int turn){
	bool validMoveFlag = false;
	bool flag = false;
	moves.clear();
	//end will keep track of the pieces to turn.
	int end = 0;
	for (int x = 0; x < SIDE_LENGTH; x ++){
		for (int y = 0; y < SIDE_LENGTH; y ++){
			if (board[x][y] == turn){
				continue;
			}
			flag = false;
			
			if (x < SIDE_LENGTH-1 && board[x+1][y] != turn){

				for (int i = x+1; i < SIDE_LENGTH; i ++){

					if (board[i][y] == turn){

						//please be ok to do :()
						int * pleaseNoMemoryLeaks = new int [2];
						pleaseNoMemoryLeaks[0] = x;
						pleaseNoMemoryLeaks[1] = y;
						moves.push_back(pleaseNoMemoryLeaks);
						flag = true;
						break;

					}
					else if (board[i][y] == 0){
						break;
					}

				}
				

			}
			if (flag){
					continue;
			}
			
			
			//to the left
			//flag will keep track if there is anything to flip
			flag = false;

			//end will keep track of the pieces to turn.
			end = 0;
			if (x > 0 && board[x-1][y] != turn){

				for (int i = x-1; i >= 0; i = i - 1){
					
					if (board[i][y] == turn){
						//please be ok to do :()
						int * pleaseNoMemoryLeaks = new int [2];
						pleaseNoMemoryLeaks[0] = x;
						pleaseNoMemoryLeaks[1] = y;
						moves.push_back(pleaseNoMemoryLeaks);
						flag = true;
						break;

					}
					else if (board[i][y] == 0){
						break;
					}

				}

				
			}
			if (flag){
				continue;
			}

			//y up
			//flag will keep track if there is anything to flip
			flag = false;

			//end will keep track of the pieces to turn.
			end = 0;
			if (y < SIDE_LENGTH-1 && board[x][y+1] != turn){
				for (int i = y+1; i < SIDE_LENGTH; i ++){
					if (board[x][i] == turn){
						//please be ok to do :()
						int * pleaseNoMemoryLeaks = new int [2];
						pleaseNoMemoryLeaks[0] = x;
						pleaseNoMemoryLeaks[1] = y;
						moves.push_back(pleaseNoMemoryLeaks);
						flag = true;
						break;

					}
					else if (board[x][i] == 0){
						break;
					}

				}
			}
			if (flag){
				continue;
			}
			//y down

			flag = false;

			//end will keep track of the pieces to turn.
			end = 0;
			if (y > 0 && board[x][y-1] != turn){
				for (int i = y-1; i >= 0; i = i - 1){
					
					if (board[x][i] == turn){
						//please be ok to do :()
						int * pleaseNoMemoryLeaks = new int [2];
						pleaseNoMemoryLeaks[0] = x;
						pleaseNoMemoryLeaks[1] = y;
						moves.push_back(pleaseNoMemoryLeaks);
						flag = true;
						break;

					}
					else if (board[x][i] == 0){
						break;
					}

				}
				
			}
			if (flag){
				continue;
			}

			flag = false;
			//diagonals 
			//check down left
			if (y > 0 && x>0 && board[x-1][y-1] != turn&& board[x-1][y-1] != 0){
				int i = 1;
				while (x-i > 0 && y-i > 0){
					i = i +1;
					if (board[x-i][y-i] == turn){
						//please be ok to do :()
						int * pleaseNoMemoryLeaks = new int [2];
						pleaseNoMemoryLeaks[0] = x;
						pleaseNoMemoryLeaks[1] = y;
						moves.push_back(pleaseNoMemoryLeaks);
						flag = true;
						break;

					}
					//Check if its empty
					else if (board[x-i][y-i] == 0){
						break;
					}

				}
				//So we know know we should turn the peices over	
			}
			if (flag){
				continue;
			}
			flag = false;
			//right down
			if (y > 0 && x < SIDE_LENGTH-1 && board[x+1][y-1] != turn&& board[x+1][y-1] != 0){
				int i = 1;
				while (x+i < SIDE_LENGTH && y-i > 0){
					i = i +1;
					if (board[x+i][y-i] == turn){
						//This is the stuff in the middle so set the flag to true and set the end
						//please be ok to do :()
						int * pleaseNoMemoryLeaks = new int [2];
						pleaseNoMemoryLeaks[0] = x;
						pleaseNoMemoryLeaks[1] = y;
						moves.push_back(pleaseNoMemoryLeaks);
						flag = true;
						break;

					}
					//Check if its empty
					else if (board[x+i][y-i] == 0){
						break;
					}

				}
				//So we know know we should turn the peices over
				
			}
			if (flag){
				continue;
			}
			flag = false;
			//left up
			if (y < SIDE_LENGTH-1 && x > 0 && board[x-1][y+1] != turn&& board[x-1][y+1] != 0){
				int i = 1;
				while (x-i > 0 && y+i <SIDE_LENGTH){
					i = i +1;
					if (board[x-i][y+i] == turn){
						//This is the stuff in the middle so set the flag to true and set the end
						int * pleaseNoMemoryLeaks = new int [2];
						pleaseNoMemoryLeaks[0] = x;
						pleaseNoMemoryLeaks[1] = y;
						moves.push_back(pleaseNoMemoryLeaks);
						flag = true;
						break;

					}
					//Check if its empty
					else if (board[x-i][y+i] == 0){
						break;
					}

				}
				//So we know know we should turn the peices over
				
			}
			if (flag){
				continue;
			}
			flag = false;
			//left up
			if (y < SIDE_LENGTH-1 && x < SIDE_LENGTH-1 && board[x+1][y+1] != turn&& board[x+1][y+1] != 0){
				int i = 1;
				while (x+i <SIDE_LENGTH && y+i <SIDE_LENGTH){
					i = i +1;
					if (board[x+i][y+i] == turn){
						//This is the stuff in the middle so set the flag to true and set the end
						int * pleaseNoMemoryLeaks = new int [2];
						pleaseNoMemoryLeaks[0] = x;
						pleaseNoMemoryLeaks[1] = y;
						moves.push_back(pleaseNoMemoryLeaks);
						flag = true;
						break;

					}
					//Check if its empty
					else if (board[x+i][y+i] == 0){
						break;
					}
				}
			}
			if (flag){
				continue;
			}
		}
	}
			
}
//Of course this should be rewritten to condense the code into a few loops but im lazy
//Places a peice on the board
int Board::placePiece(int x, int y, int turn){
	bool validMoveFlag = false;
	//Check if out of bounds
	if (x < 0 || x >= SIDE_LENGTH || y < 0 || y >= SIDE_LENGTH) {
		return OutOfBounds;
	}
	//check is space is filled
	if (board[x][y] != 0){
		return Occupied;
	}

	else{
		//switch blank to turn
		board[x][y] = turn;
		//Decide whether or not to flip the pieces in the middle



		//right
		//flag will keep track if there is anything to flip
		bool flag = false;

		//end will keep track of the pieces to turn.
		int end = 0;
		if (x < SIDE_LENGTH-1 && board[x+1][y] != turn){
			for (int i = x+1; i < SIDE_LENGTH; i ++){
				if (board[i][y] == turn){
					//This is the stuff in the middle so set the flag to true and set the end
					end = i;
					flag = true;
					break;
				}
				else if (board[i][y] == 0){
					break;
				}

			}
			if (flag){
				for (int i = end; i > x; i --){
					board[i][y] = turn;
					validMoveFlag = true;
				}
			}
		}
		//to the left
		//flag will keep track if there is anything to flip
		flag = false;

		//end will keep track of the pieces to turn.
		end = 0;
		if (x > 0 && board[x-1][y] != turn){

			for (int i = x-1; i >= 0; i = i - 1){
				
				if (board[i][y] == turn){
					//This is the stuff in the middle so set the flag to true and set the end
					end = i;
					flag = true;


				}
				else if (board[i][y] == 0){
					break;
				}

			}
			if (flag){
				
				for (int i = end; i < x; i ++){
						board[i][y] = turn;
						validMoveFlag = true;
				}
			}
		}

		//y up
		//flag will keep track if there is anything to flip
		flag = false;

		//end will keep track of the pieces to turn.
		end = 0;
		if (y < SIDE_LENGTH-1 && board[x][y+1] != turn){
			for (int i = y+1; i < SIDE_LENGTH; i ++){
				if (board[x][i] == turn){
					//This is the stuff in the middle so set the flag to true and set the end
					end = i;
					flag = true;
					break;
				}
				else if (board[x][y] == 0){
					break;
				}

			}
			if (flag){

					for (int i = end; i > y; i --){
						board[x][i] = turn;
						validMoveFlag = true;
				}
			}
		}


		//y down

		flag = false;

		//end will keep track of the pieces to turn.
		end = 0;
		if (y > 0 && board[x][y-1] != turn){

			for (int i = y-1; i >= 0; i = i - 1){
				
				if (board[x][i] == turn){
					//This is the stuff in the middle so set the flag to true and set the end
					end = i;
					flag = true;

				}
				else if (board[x][i] == 0){
					break;
				}

			}
			if (flag){
				
				for (int i = end; i < y; i ++){
						board[x][i] = turn;
						validMoveFlag = true;
				}
			}
		}

		flag = false;
		//diagonals 
		//check down left
		if (y > 0 && x>0 && board[x-1][y-1] != turn&& board[x-1][y-1] != 0){
			int i = 1;
			while (x-i > 0 && y-i > 0){
				i = i +1;
				if (board[x-i][y-i] == turn){
					//This is the stuff in the middle so set the flag to true and set the end
					end = i;
					flag = true;

				}
				//Check if its empty
				else if (board[x-i][y-i] == 0){
					break;
				}

			}
			//So we know know we should turn the peices over
			if (flag){
				
				while(x-i < x && y-i < y){
					i = i -1;
					board[x-i][y-i] = turn;
					validMoveFlag = true;
				}
			}
		}
		flag = false;
		//right down
		if (y > 0 && x < SIDE_LENGTH-1 && board[x+1][y-1] != turn&& board[x+1][y-1] != 0){
			int i = 1;
			while (x+i < SIDE_LENGTH && y-i > 0){
				i = i +1;
				if (board[x+i][y-i] == turn){
					//This is the stuff in the middle so set the flag to true and set the end
					end = i;
					flag = true;

				}
				//Check if its empty
				else if (board[x+i][y-i] == 0){
					break;
				}

			}
			//So we know know we should turn the peices over
			if (flag){
		
				while(x+i > x && y-i < y){
					i = i -1;
					board[x+i][y-i] = turn;
					validMoveFlag = true;
				}
			}
		}
		flag = false;
		//left up
		if (y < SIDE_LENGTH-1 && x > 0 && board[x-1][y+1] != turn&& board[x-1][y+1] != 0){
			int i = 1;
			while (x-i > 0 && y+i <SIDE_LENGTH){
				i = i +1;
				if (board[x-i][y+i] == turn){
					//This is the stuff in the middle so set the flag to true and set the end
					end = i;
					flag = true;

				}
				//Check if its empty
				else if (board[x-i][y+i] == 0){
					break;
				}

			}
			//So we know know we should turn the peices over
			if (flag){
				
				while(x-i < x && y+i > y){
					i = i -1;
					board[x-i][y+i] = turn;
					validMoveFlag = true;
				}
			}
		}
		flag = false;
		//left up
		if (y < SIDE_LENGTH-1 && x < SIDE_LENGTH-1 && board[x+1][y+1] != turn&& board[x+1][y+1] != 0){
			int i = 1;
			while (x+i <SIDE_LENGTH && y+i <SIDE_LENGTH){
				i = i +1;
				if (board[x+i][y+i] == turn){
					//This is the stuff in the middle so set the flag to true and set the end
					end = i;
					flag = true;

				}
				//Check if its empty
				else if (board[x+i][y+i] == 0){
					break;
				}

			}
			//So we know know we should turn the peices over
			if (flag){
				
				while(x+i > x && y+i > y){
					i = i -1;
					board[x+i][y+i] = turn;
					validMoveFlag = true;
				}
			}
		}


		//If its an invalid move then dont turn anything and return as such
		if (!validMoveFlag){
			board[x][y] =0;

			return InvalidMove;
		}
		
		return Success;
	}
}
