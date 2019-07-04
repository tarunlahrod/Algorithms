#include<bits/stdc++.h>
using namespace std;



//--------------------------------------------------------------//
//                      Unoptimised Code                        //
//--------------------------------------------------------------//

int ways(int n, int m){
    // Base Case
    if(n == 0 || n == 1)
        return 1;
    
    int ans=0;
    
    // Recursive Case
    for(int i=1; i<=m && i<=n; i++)
        ans += ways(n-i, m);
    
    return ans;
}
//--------------------------------------------------------------//



//--------------------------------------------------------------//
//              Optimised Code (using memoization)                      //
//--------------------------------------------------------------//

int memo[200] = {0};

int waysMemo(int n, int m){
    // Base Case
    if(n == 0 || n == 1)
        return 1;
    
    // if(memo[n] != 0)
    //     return memo[n];
    // memo[n] = ways(n, m);
    
    
    // Recursive Case
    
    if(memo[n] != 0){     // means the ans is in the memo
        return memo[n];
    }
    
    // if here means answer is not present in the memo
    
    int ans=0;
        
    for(int i=1; i<=m && i<=n; i++){
        ans += ways(n-i, m);
    }
    
    memo[n] = ans;
    
    return ans;
}

//--------------------------------------------------------------//


int main(){
    int n, m;       // n stairs and atmost m steps at a time
    cin>>n>>m;
    int ans = waysMemo(n, m);
    cout<<ans<<endl;
}