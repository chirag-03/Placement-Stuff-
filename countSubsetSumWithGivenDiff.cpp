#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(int arr[], int n, int sum){
    int dp[n+1][sum+1];
    for(int i=0; i<n+1; i++){
        for(int j=0; j<sum+1; j++){
            if(i==0)
            dp[i][j]=0;
            if(j==0)
            dp[i][j]=1;
        }
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 1; i < sum+1; j++)
        {
            if(arr[i-1]<=j)
            dp[i][j]=dp[i-1][j]+dp[i-1][j-arr[i-1]];
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int countOfSubsetWithDiff(int arr[], int n, int diff){
    int arrSum=0;
    for(int i=0; i<n; i++)
    arrSum+=arr[i];

    int sum=0;
    sum=(arrSum+diff)/2;
    return countSubsetSum(arr,n,sum);
}
int main(){
    
    return 0;
}