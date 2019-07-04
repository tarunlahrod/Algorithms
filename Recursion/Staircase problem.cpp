#include<bits/stdc++.h>
using namespace std;

// This is similar to a fibonacci sequence except for n = 0, it gives output 1
// and in a fibonacci sequence, for n = 0, output is 0. But this is not a good program. 
// This can be optimised. Check the findWaysOptimised() function.
int findWays(int n){
	// For stair with n = 0, we are already reached 'n' i.e. 0
	// So for n = 0, ways = 1.

	// Similarly, for n = 1, we can reach in one step to the 1st stair
	// Therefore, for n = 1, ways = 1.

	// For n = 2, we now have two choices, we take 1 step or we take 3 steps.
	// If we take 1 step, the our problem gets reduced to 'n = 1' case and if
	// we take 2 steps, out problem gets reduced to 'n = 0' case.

	// Hence the base case
	if(n == 0 || n == 1)
		return 1;

	// Recursive case
	return findWays(n-1) + findWays(n-2);
}

// Optimised function for fibonacci-like sequence using Memoization
// Our memo for saving the values

int memo[100] = {0};

int findWaysOptimised(int n){
	if(n == 0 || n == 1)
		return 1;

	if(memo[n] != 0)
		return memo[n];
	memo[n] = findWaysOptimised(n-1) + findWaysOptimised(n-2);
	return memo[n];
}

int main(){
	int n;
	cout<<"Enter number of stairs, n : ";
	cin>>n;
	int ways = findWaysOptimised(n);
	cout<<"You can reach "<< n <<" stairs in "<< ways <<" ways.\n";

	return 0;
}