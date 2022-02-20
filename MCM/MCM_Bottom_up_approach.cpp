#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int solve(int arr[],int i,int j){
    if(i>=j)
    return 0;
    int mn=INT_MAX;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    for(int k=i; k<=j-1; k++){
        int temp=solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(temp<mn){
            mn=temp;
        }
        dp[i][j]=mn;
    }
    return dp[i][j];
}
int MCM(int n, int arr[]){
    memset(dp,-1,sizeof(dp));
    return solve(arr, 1, n-1);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
       cin>>arr[i];
    }
    cout<<MCM(n,arr);
    return 0;
}