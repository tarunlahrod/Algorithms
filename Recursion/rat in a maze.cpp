//								RAT IN A MAZE

// There is a maze and a rat at S.
// The rat is only allowed to move right or down. 
// Print all the possible paths from S to E.
// Blocks with 'x' are blocked.
// Show all the possible paths by 1's.


#include<iostream>
using namespace std;

#define Rows 6
#define Cols 6
char mazeMatrix[Rows][Cols] = {
						{'S', ' ', ' ', ' ', ' ', 'x'},
						{' ', 'x', 'x', ' ', ' ', ' '},
						{' ', 'x', 'x', ' ', 'x', ' '},
						{' ', ' ', ' ', 'x', ' ', ' '},
						{' ', 'x', ' ', ' ', ' ', ' '},
						{' ', ' ', ' ', 'x', ' ', 'E'}};

void printMaze(){
	for(int i=0; i<Rows; i++){
		cout<<endl<<"|";
	for(int j=0; j<Cols; j++)
			cout<<mazeMatrix[i][j]<<"|";
	}
	cout<<endl;
}

int findPath(int i, int j){

	// reached the end
	if(mazeMatrix[i][j] == 'E'){
		return 1;
	}

	// reached bottom end
	if(i >= Rows){
		return 0;
	}

	//reached right boundary/end
	if(j >= Cols){
		return 0;
	}

	// blocked by wall 
	if(mazeMatrix[i][j] == 'x'){
		return 0;
	}

	if(findPath(i+1,j) || findPath(i, j+1)){
		// move one step downward
		if(findPath(i+1, j)){
			mazeMatrix[i][j] = '1';
		}

		// move one step right
		if(findPath(i, j+1)==1){
			mazeMatrix[i][j] = '1';
		}
		return 1;
	}
}


int main(){
	printMaze();
	int pathPossible = findPath(0, 0);
	printMaze();
	return 0;
}