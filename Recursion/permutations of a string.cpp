#include<iostream>
using namespace std;

void printPermutations(char *input, int i){
	// base case
	if(input[i]=='\0'){
		cout<<input<<endl;
		return;
	}

	// recursive case
	for(int j=i; input[j]!='\0'; j++){
		swap(input[i], input[j]);
		printPermutations(input, i+1);
		// Backtrack to restore the original array
		swap(input[i], input[j]);
	}
}

int main(){
	char input[] = "abc";
	printPermutations(input, 0);

	return 0;
}