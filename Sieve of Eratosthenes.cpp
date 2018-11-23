#include<iostream>
using namespace std;

void primeClassical(long a,long b)		//	finding primes between a and b
{
	for(long j=a;j<=b;j++)
	{
		if(j==1)
			continue;
		int flag=0;
		for(long i=2;i<=j/2;i++)
		{
			if(j%i == 0)
			{
				flag=1; 
				break;
			}
		}
		if(!flag)
			cout<<j<<endl;
	}
}


void primeBySieveofEratosthenes(long a, long b)
{
	// first we'll find primes between zero and a number 'a'
	//declaring a boolean array of required size
	bool numArray[a];
	for(int i = 0 ; i<a ;i++)
		numArray[i] = true ;

	for(int i=2;i<a;i++)
	{
		if(numArray[i])			//if numArray[i] is true
		{
			for(int n = 2; numArray[i]*n < a ; n++)   // n is the multiple
				numArray[numArray[i]*n] = false;				  //removing all the mutliples of numArray[i]
		}
	}

	for(int i = 2;i<a;i++)
		if(numArray[i])
			cout<<i<<" ";
}

int main()
{
	long a=100,b=1000000;
	int t=1;
	primeBySieveofEratosthenes(a,b);
	// //making the test case to follow and perform the given task
	// cin>>t;
	// while(t--)
	// {
	// 	cin>>a>>b;
	// 	fun(a,b);
	// 	cout<<endl;
	// }
	//cout<<"hi chal rha";
}