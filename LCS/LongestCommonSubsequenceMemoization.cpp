#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int lcs(string s1, string s2, int n, int m){
    int dp[1000][1000];
        n=s1.length();
        m=s2.length();
        if(n==0 || m==0){
            return 0;
        }
        if(t[n][m]!=-1){
            return t[n][m];
        }
        if(s1[n-1]==s2[m-1]){
           return 1+lcs(s1,s2,n-1,m-1);
        }
        else{
            return max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
        }
        return t[n][m];
    }
    int main(){
        string s1;
        string s2;
        cin>>s1;
        cin>>s2;
        int n=s1.length();
        int m=s2.length();
        memset(t,-1,sizeof(t));
        cout<<lcs(s1,s2,n,m);
        return 0;
    }