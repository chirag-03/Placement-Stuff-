#include<bits/stdc++.h>
using namespace std;

//Recursive code 
int knapsack(int wt[], int val[], int W, int n){
    if(W==0 || n==0){
        return 0;
    }
    if(wt[n-1]<=W){
        return max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    }
    else if(wt[n-1]>W)
    return knapsack(wt,val,W,n-1);
}

// Memoization
int static t[102][1002];
int knapsack(int wt[], int val[], int W, int n){
    if(W==0 || n==0){
        return 0;
    }
    if(t[n][W]!=-1)
    return t[n][W];
    
    if(wt[n-1]<=W){
        t[n][W]=max(val[n-1]+knapsack(wt,val,W-wt[n-1],n-1),knapsack(wt,val,W,n-1));
    }
    else if(wt[n-1]>W){
        t[n][W]=knapsack(wt,val,W,n-1);
    }
}

// Top down approach
int knasack(int wt[], int val[], int W, int n){
    int dp[n+1][W+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<W+1; j++){
            if(i==0)
            dp[i][j]=0;
            if(j==0)
            dp[i][j]=1;
        }
    }
    for(int i=1; i<n+1; i++){
        for(int j=1; j<W+1; j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
            }
            else if(wt[i-1]>j){
                dp[i][j]=t[i-1][j];
            }
        }
    }
   return t[n][W];
}

int main(){
    return 0;
}