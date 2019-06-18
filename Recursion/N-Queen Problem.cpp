/*
Place N-Queens on a NxN chess board such that all queens are safe.
*/

#include<iostream>
using namespace std;

void printBoard(int board[][15], int n){
	for(int i=0; i<n; i++){
			cout<<endl;
			for(int j=0; j<n; j++){
				if(board[i][j] == 1)
					cout<<"Q ";
				else
					cout<<"_ ";
			}
		}
		cout<<endl;
}

bool isSafe(int board[][15], int i, int j, int n){
	/* 
	We will check for:
		1. Upper right diagonal
		2. Upper left diagonal
		3. Upper column
	*/

	// Check for column
	for(int row=0; row<i; row++){
		if(board[row][j] == 1)		// means there's a queen at that position already
			return false;
	}

	// Check for left diagonal
	int x = i;
	int y = j;
	while(x>=0 && y>=0){
		if(board[x][y] == 1)
			return false;
		x--;	y--;
	}

	// Check for right diagonal
	x = i;
	y = j;
	while(x>=0 && y<n){
		if(board[x][y] == 1)
			return false;
		x--;	y++;
	}

	// The position is now safe, return true
	return true;
}

/*
function solveNQueen() takes 3 arguments:
	1. board array
	2. current row
	3. total number of rows (or columns = n)
*/
bool solveNQueen(int board[][15], int i, int n){
	// Base Case
	if(i==n){
		// You have successfully placed queens in n rows (0...n-1)
		// Print the board
		printBoard(board, n);
		// return true;		// comment out this statement to print all possible cases
	}

	// Recursive Case
	// While solving using recursion, we assume that my subgird will be solved.
	// Try to place the queen in the current row and call on the remaining part which will be solved by recursion.
	// So iterating over all the columns in the current row.
	for(int j=0; j<n; j++){
		// We must check if the (i,j)th position is safe to place the queen or not.
		if(isSafe(board, i, j, n)){
			// Place the Queen - Assuming (i,j) is the right position.
			board[i][j] = 1;

			bool possibleToPlaceNextQueen = solveNQueen(board, i+1, n);
			if(possibleToPlaceNextQueen){
				return true;
			}
			// If reached here, it means that (i,j) is not the right position for placing the Queen.
			// Our assumption is wrong.
			board[i][j] = 0;	// Backtrack
		}
	}
	// We have tried for all the positons but found no "safe" place for Queen
	return false;
}

int main(){
	int n;
	cout<<"Give me n: ";
	cin>>n;
	int board[15][15] = {0};
	solveNQueen(board, 0, n);
	
	return 0;
}