#include<bits/stdc++.h>
using namespace std;
// Memoization step
int f(int n, vector<int>&dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]=f(n-1,dp)+f(n-2,dp);
}
 int main(){
    int n; cin>>n;
    // vector<int> dp(n+1,-1);
    // cout<<f(n, dp);

    // Tabulation Time complexity=O(n) space Complexity=O(n)
    // dp[0]=0;
    // dp[1]=1;
    // for(int i=2; i<=n; i++){
    //     dp[i]=dp[i-1]+dp[i-2];
    // }
    // cout<<dp[n];

    // Tabulation Time complexity=O(n) space Complexity=O(1)
    int prev2=0;
    int prev=1;
    for(int i=2; i<=n; i++){
        int curr_i=prev2+prev;
        prev2=prev;
        prev=curr_i;
    }
    cout<<prev<<endl;
    return 0;
 }