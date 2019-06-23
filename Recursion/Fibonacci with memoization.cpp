#include<iostream>
using namespace std;

int a[50] = {0};

int fib(int n){
	if(n == 0 || n == 1)
		return n;

	if(a[n] != 0)
		return a[n];

	a[n] = fib(n-1) + fib(n-2);
	return a[n];
}

int main(){
	int n = fib(5);
	cout<<n<<"\n";

	return 0;
}