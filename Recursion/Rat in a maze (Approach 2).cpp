 //								RAT IN A MAZE

// There is a maze and a rat at S.
// The rat is only allowed to move right or down. 
// Print all the possible paths from S to E.
// Blocks with 'x' are blocked.
// Show all the possible paths by 1's.


#include<iostream>
using namespace std;

bool solvemaze(char maze[][20], int sol[][20], int i, int j, int m, int n){
	// Base Case
	if(i==m && j==n){
		sol[i][j] = 1;

		for(int i=0; i<=m; i++){
			cout<<"\n";
			for(int j=0; j<=n; j++){
				cout<<sol[i][j]<<" ";
			} 
		}
		cout<<"\n";
		// return true;		// Comment this out to get all the possible paths
	}

	// Recursive case
	// Assuming rat passes through current cell
	sol[i][j] = 1;

	// Try moving right
	if(j+1<=n && maze[i][j+1]!='X'){
		bool rightPathway = solvemaze(maze, sol, i, j+1, m, n);
		if(rightPathway){
			return true;
		}
	}

	// Try moving down
	if(i+1<=m && maze[i+1][j]!='X'){
		bool downPathway = solvemaze(maze, sol, i+1, j, m, n);
		if(downPathway){
			return true;
		}
	}

	// If reached here, means assumption is wrong. 
	// Backtrack and set sol[i][j] = 0;
	sol[i][j] = 0;
	return false;
}


int main(){
	char maze[20][20] = {
						"0000",
						"0XX0",
						"0XXX",
						"0000",
						"X000"
						};

	int sol[20][20] = {0};
	solvemaze(maze, sol, 0, 0, 4, 3);


	return 0;
}