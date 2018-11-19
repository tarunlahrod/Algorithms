//reference from mycodingschool
//https://www.youtube.com/watch?v=nO7_qu2kd1Q


//			MODULAR EXPONENTIATION

/*
		say we have a number 'a' 
		raised to the power 'n'. 
		We need to find the remainder
		when the number a^n is 
		divided by another number 'm'
*/

#include<iostream>
using namespace std;
int fn(int a,int n,int m)
{
	if (n==0)
		return 1;

	int ans = fn(a,n/2,m);

	if(n%2)	//a is odd
		return (ans*ans*a)%m;
	else //a is even
		return (ans*ans)%m;
}

int main()
{
	int a = fn(5,3,7);
	cout<<a<<endl;
}