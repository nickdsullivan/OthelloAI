/*
Author: nickdsullivan@gmail.com
Header file for Board.cpp
*/

#pragma once
#include <iostream>
#include <vector>
#ifndef SIDE_LENGTH
#define SIDE_LENGTH 8
#endif
enum errorList{
	Success = 0, OutOfBounds = 1, Occupied = 2, InvalidMove=3,
};
enum winList{
	NoWinner = 0, Player1Wins = 1, Player2Wins,
};
enum pieceType{
	Empty = 0, Black = 1, White = 2,
};

class Board{
	public:
		Board();
		~Board();
		//Will place the piece and return true or will calculate if it is invalid and return false
		//If the cordinates are out of bounds it will return what happend
		//I know this can be condensed into better code relax its a personal project.
		int placePiece(int x, int y,int turn);
		//Check 
		int checkWin();
		void display();
		int** board;
		void restart();

		//This is a terrible way to do this.  However I am doing this way.  
		void returnValidMoves(std::vector<int*>& moves, int turn);	
	
		
};
