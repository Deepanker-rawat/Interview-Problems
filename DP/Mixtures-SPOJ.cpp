#include <bits/stdc++.h>
using namespace std;

int arr[1000]
int dp[1000][1000];

long long sum(int s, int e){
    long long ans=0;
    for(int i=s; i<=e;i++){
        ans+= arr[i];
        ans %= 100;
    }
    return ans;
}
int solve(int i, int j){
    //Base case
    if(i>=j){
        return 0;
    }

    //If the answer is already there
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    //We break our expression at every possible k

    dp[i][j] = INT_MAX;
    for(int k=i; k<=j; k++){
        dp[i][j] = min(dp[i][j], solve(i,k) + solve(k+1,j) + sum(i,k) * sum(k+1.j));
    
    }

    return dp[i][j];
}


int main() {
 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
 
        freopen("output.txt", "w", stdout);
 
    #endif
 
    int t;
    cin>>t;
 
    while(t--){
        int n;
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        memeset(dp, -1, sizeof(dp));

        cout<<solve(0, n-1)
    }
}