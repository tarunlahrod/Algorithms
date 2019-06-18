#include<iostream>
using namespace std;

void printSubsequence(char *input, char *output, int i, int j){
	// Base case
	if(input[i] == '\0'){
		output[j] = '\0';
		cout<<output<<endl;
		return;
	}

	// Two case:
	// 1. Current input character lelo
	output[j] = input[i];
	printSubsequence(input, output, i+1, j+1);

	// 2. Current input character mat lo
	printSubsequence(input, output, i+1, j);
}

int main(){
	char input[] = "123456";
	char output[100]; 
	printSubsequence(input, output, 0, 0);	
}