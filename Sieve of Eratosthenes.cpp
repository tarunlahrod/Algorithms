/*					Sieve of Eratosthenes
	This is a method to find all the prime numbers from 0 to any number.
	It is one of the most efficient method.
	If anyone can make this code better, please make it. Thanks.
*/

#include<iostream>
using namespace std;

void primeBySieveofEratosthenes(long a)
{
	// first we'll find primes between zero and a number 'a'
	//declaring a boolean array of required size
	bool numArray[a];
	for(int i = 0 ; i<a ;i++)
		numArray[i] = true ;  	// setting all values true initially
			      		// true means it is a prime number, we are assuming that all are prime numbers
					// we will remove them in the next loop (by making their value = false.

	for(int i=2;i<a;i++)
	{
		if(numArray[i])			//if numArray[i] is true
		{
			for(int n = 2; numArray[i]*n < a ; n++)   		// n is the multiple
				numArray[numArray[i]*n] = false;		//removing all the mutliples of numArray[i]
		}
	}
	
	//for printing the primes (or the "true" values)
	for(int i = 2 ; i < a ; i++)
		if(numArray[i])			// if numArray is true, then print it's index (which is nothing but the number itself
			cout<<i<<" ";		// else do nothing just update and keep iterating.
}

int main()
{
	long a = 100;
	primeBySieveofEratosthenes(a);
}
