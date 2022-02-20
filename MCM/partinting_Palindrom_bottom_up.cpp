#include<bits/stdc++.h>
using namespace std; 

bool isPalindrome(string s, int i ,int j){
    if(i>=j){
        return true;
    }
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}
int dp[1001][1001];
int solve(string s, int i, int j){
    if(i>=j){
        return 0;
    }
    
    if(isPalindrome(s,i,j)){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn=INT_MAX;
    for(int k=i; k<=j-1; k++){
        int temp=1+solve(s,i,k)+solve(s,k+1,j);
        mn=min(temp,mn);
    }
    dp[i][j]=mn;
    return dp[i][j];
}
int palindromePart(string s){
    memset(dp,-1,sizeof(dp));
    int n=s.length()-1;
    int ans=solve(s,0,n);
    return ans;
}
int main(){
    string s;
    cin>>s;
    cout<<palindromePart(s);
    // cout<<solve(s,0,s.length()-1);
    // cout<<isPalindrome(s,0,s.length()-1);
    return 0;
}

// ababbbabbababa