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
        i++;
        j--;
    }
    return true;
}
int solve(string s, int i, int j){
    if(i>=j){
        return 0;
    }
    if(isPalindrome(s,i,j)==true){
        return 0;
    }
    int mn=INT_MAX;
    for(int k=i; k<=j-1; k++){
        int temp=1+solve(s,i,k)+solve(s,k+1,j);
        mn=min(temp,mn);
    }
    return mn;
}
int main(){
    string s;
    cin>>s;
    cout<<solve(s,0,s.length()-1);
    return 0;
}

// ababbbabbababa