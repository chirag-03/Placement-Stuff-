#include<bits/stdc++.h>
using namespace std;

int lrs(string s1, string s2, int m, int n){
    int dp[m+1][n+1];
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n+1; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1; i<m+1; i++){
        for(int j=1; j<n+1; j++){
            if(s1[i-1]==s2[j-1] && i!=j){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else{
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}
int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    cout<<lrs(s1,s2,m,n);
    return 0;
}