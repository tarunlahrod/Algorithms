/*
Linear Search using recursive method.
*/

#include<iostream>
using namespace std;

int search2(int *a, int n, int i, int key){
	// base case
	if(i==n) // if i reaches n, means we have traversed the whole array and didn't found anything
		return -1;

	// recursive case
	if(a[i]==key)
		return i;

	int chotaIndex = search2(a, n, i+1, key);
	return chotaIndex;
}

int search(int *a, int n, int key){
	if(n==0)	//base case
		return -1;
	
	// Recursive case
	if(a[0] == key)
		return 0;

	int chotaIndex = search(a+1, n-1, key); // chotaIndex is the index of the element in the subarray
							
	if(chotaIndex == -1)		// propagating -1 through the array if the element is not found
		return -1;

	return chotaIndex + 1;
}

int main(){
	int a[] = {2,3,6,5,9,4};
	int n = sizeof(a)/sizeof(int);
	int i, j;
	i = search(a, n, 9);
	j = search2(a, n, 0, 9);
	cout<<"By method 1: "<<i<<endl;
	cout<<"By method 2: "<<j<<endl;
}
