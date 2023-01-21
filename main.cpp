#include<iostream>
#include "board.h"
#include <vector>
using namespace std;
int main() {
  Board* b = new Board();
  vector <int*> moves;
  b->display();
  int x;
  int y;
  while (true){

   b->returnValidMoves(moves,1);

   for (int i = 0; i < moves.size(); i ++){
      cout << "("<< moves[i][0] << "," << moves[i][1]<<")";
   }
   cout <<endl;
  
   std::cin >>x;
   std::cin >>y;
   if (x == 8){
      delete(b);
      break;
   }
   b->placePiece(x,y,1);
   
   b->display();
  }
  
  return 0;
}




