#include<iostream>
using namespace std;

void print(int *a, int i, int n){
	if(i==n)
		return;

	cout<<a[i]<<" ";
	return print(a, i+1, n);
}

void swap(int &a, int &b){
	int t=a;
	a=b; b=t;
}

void bsort(int *a, int j, int n){
	if(n==0||n==1)
		return;

	if(j==n-1){
		bsort(a, 0, n-1);		// works as outer for loop
		return;
	}

	if(a[j]>a[j+1])
		swap(a[j], a[j+1]);

	bsort(a, j+1, n);			// works as inner for loop
}

int main(){
	int a[] = {5,4,3,2,1};
	int n = sizeof(a)/sizeof(int);
	bsort(a, 0, n);
	print(a, 0, n);
}