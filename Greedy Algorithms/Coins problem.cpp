/*
								Coins problem
Problem: We are given a set of coins and our task is to form a sum of 
money n using the coins. The values of the coins are coins = { c 1 , c 2 , . . . , c k },
and each coin can be used as many times we want. What is the minimum 
number of coins needed?

For example, if the coins are the euro coins (in cents)
{1, 2, 5, 10, 20, 50, 100, 200} and n = 520, we need 
at least four coins. The optimal solution is to select coins
200 + 200 + 100 + 20 whose sum is 520.
*/


#include<iostream>
#include<algorithm>
using namespace std;

// using greedy approach, we'll look for the coin with greatest value in every iteration
void  findLeastCoins(int *coins, int n, int reqdSum){
    int sum = 0, j = 0;
    int output[100] = {0};
    sort(coins, coins+n, greater<int>());       // sorted in desc order (must include <algorithm> header file)
    int i = 0;
    while(sum < reqdSum){
        int difference = reqdSum - sum;
        if(difference < coins[i]){
            i++;
            continue;
        }
        else{
            int currentCoin = difference/coins[i];
            sum = sum + currentCoin*coins[i];
            // adding the coins to the output array
            while(currentCoin--)
                output[j++] = coins[i];
        }
    }

    // output array
    for(int i=0; i<j; i++)
        cout<<output[i]<<" ";
    cout<<"\n";
}

int main(){
    int coins[] = {1,2,5,10,20,50,100,200};
    int n = sizeof(coins)/sizeof(int);
    int sum;
    cout<<"Enter the sum to be made: ";
    cin>>sum;
    findLeastCoins(coins, n, sum);
    return 0;
}
