#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int lcs(string s1, string s2, int n, int m){
        n=s1.length();
        m=s2.length();
        if(n==0 || m==0){
            return 0;
        }
       
        if(s1[n-1]==s2[m-1]){
           return 1+lcs(s1,s2,n-1,m-1);
        }
        else{
            return max(lcs(s1,s2,n,m-1),lcs(s1,s2,n-1,m));
        }
    }