#include <bits/stdc++.h>
using namespace std;

int fib(int n, int dp[]) {
    if (n == 0 or n == 1) {
        return n;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}
int main() {
    int n = 3;
    int arr[n + 1];
    memset(arr, -1, sizeof(arr));
    cout << fib(n, arr);
}