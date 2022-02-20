#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int n, int m){
    int dp[n+1][m+1];
    string s;
    for(int i=0; i<n+1; i++){
        for(int j=0; j<m+1; j++){
            if(i==0||j==0)
            dp[i][j]=0;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<m+1; j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}
void printSubsequence(string s1, string s2, int n, int m){
    int dp[n+1][m+1];
    string s="";
    lcs(s1,s2,n,m);
    int i=n, j=m;
    while (i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1]){
            s.push_back(s1[i-1]);
            i--; j--;
        }
        else{
            if(dp[i-1][j]>dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
   reverse(s.begin(),s.end());
    
}
int main(){
    string s1, s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    printSubsequence(s1,s2,n,m);
    return 0;
}