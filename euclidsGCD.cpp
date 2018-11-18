#include<iostream>
using namespace std;



/*
			Theory for Euclid's GCD
	gcd of  two numbers 'a' and 'b', that is,

			gcd(a,b) = gcd(b,a%b) , a%b != 0
	and,	gcd(a,0) = a // base case
*/

int gcd(int a, int b)
{
	if(b==0)				//base case
		return a;			

	return gcd(b,a%b);		//recursive statement
}


int main()
{
	cout<<gcd(14,10)<<endl;
}