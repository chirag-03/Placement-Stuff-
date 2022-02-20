#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n){
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
            if(s1[i-1]==s2[j-1])
            dp[i][j]=1+lcs(s1,s2,m-1,n-1);
            else
            dp[i][j]=max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
        }
    }
    return dp[m][n];
}
void printLongestCommonSubsequence(string s1, string s2, int m, int n){
    int dp[m+1][n+1];
    int i=m;
    int j=n;
    string ans;
    lcs(s1,s2,m,n);
    while(i>0 && j>0){
        if(s1[i-1]==s2[j-1]){
            ans.push_back(s1[i-1]);
            i--;
            j--;
        }
        else {
            if((dp[i][j-1]>dp[i-1][j])){
                ans.push_back(dp[i][j-1]);
                j--;
            }
            else{
                ans.push_back(dp[i-1][j]);
                i--;
            }
        }
    }
    while(i>0){
        ans.push_back(s1[i-1]);
        i--;
    }
    while(j>0){
        ans.push_back(s2[j-1]);
        j--;
    }
    reverse(ans.begin(),ans.end());
    // return ans;
}
int shortestCommonSupersequence(string s1, string s2, int m ,int n){
    

}
int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    int m=s1.length();
    int n=s2.length();
    cout<<shortestCommonSupersequence(s1,s2,m,n);
    return 0;
}