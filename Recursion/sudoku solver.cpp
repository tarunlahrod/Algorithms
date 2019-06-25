#include<iostream>
#include<math.h>
using namespace std;

bool canPlace(int mat[][9], int n, int i, int j, int number){
	// row aur col me check karo
	for(int x=0; x<n; x++){
		if(mat[x][j] == number || mat[i][x] == number){
			return false;
		}
	}

	// subgrid me check karo
	n = sqrt(n);
	int sx = (i/n)*n;
	int sy = (j/n)*n;

	for(int x=sx; x<sx+n; x++){
		for(int y=sy; y<sy+n; y++){
			if(mat[x][y] == number)
				return false;
		}
	}
	return true;
}

bool solveSudoku(int mat[][9], int i, int j, int n){
	// base case
	if(i==n){
		// print the matrix
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}

	// row ke end pe aa gaye
	if(j==n){
		return solveSudoku(mat, i+1, 0, n);
	}

	// Blue cell: do not change the already filled numbers
	if(mat[i][j]!=0){
		solveSudoku(mat, i, j+1, n);
	}

	// white cell: to be filled
	for(int number=1; number<=9; number++){
		if(canPlace(mat, n, i, j, number)){
			// rakh sakte hai to rakh do
			mat[i][j] = number;

			// aage call karo
			bool baatBani = solveSudoku(mat, i, j+1, n);

			// nahi baat bane to kuch aur try karo
			if(baatBani){
				return true;
			}
		}
	}
	//sab try kar liya, fir bhi baat na bane toh, backtrack karo
	mat[i][j] = 0;
	return false;
}

int main(){
	int mat[9][9] = {
		{5,3,0,0,7,0,0,0,0},
		{6,0,0,1,9,5,0,0,0},
		{0,9,8,0,0,0,0,6,0},
		{8,0,0,0,6,0,0,0,3},
		{4,0,0,8,0,3,0,0,1},
		{7,0,0,0,2,0,0,0,6},
		{0,6,0,0,0,0,2,8,0},
		{0,0,0,4,1,9,0,0,5},
		{0,0,0,0,8,0,0,7,9}
	};

	solveSudoku(mat, 0, 0, 9);

	return 0;
}