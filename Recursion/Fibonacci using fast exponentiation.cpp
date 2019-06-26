// nth term of Fibonacci series using fast exponentiation

#include<bits/stdc++.h>
using namespace std;

#define ull unsigned long long int

void multiply(ull F[2][2], ull M[2][2]){
	ull a00, a01, a10, a11;
	a00 = F[0][0]*M[0][0] + F[0][1]*M[1][0];
	a01 = F[0][0]*M[0][1] + F[0][1]*M[1][1];
	a10 = F[1][0]*M[0][0] + F[1][1]*M[1][0];
	a11 = F[1][0]*M[0][1] + F[1][1]*M[1][1];
	F[0][0] = a00;
	F[0][1] = a01;
	F[1][0] = a10;
	F[1][1] = a11;
}

void power(ull F[2][2], ull n){
	if(n == 0 || n == 1)
		return;
	power(F, n/2);
	multiply(F, F);	

	ull M[2][2] = {{1,1},{1,0}};
	if(n%2 != 0) 	// if n is odd
		multiply(F, M);
}

ull fib(ull n){
	if(n == 0)
		return 0;
	ull F[2][2] = {{1,1},{1,0}};
	power(F, n-1);
	return F[0][0];
}

int main(){
	int n;
	n = fib(10);
	cout<<n<<"\n";
	return 0;
}