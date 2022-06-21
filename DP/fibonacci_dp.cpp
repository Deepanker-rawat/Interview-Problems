#include <bits/stdc++.h>
using namespace std;

// method 1
// int fib(int n) {
//     int dp[100] = {0};
//     if (n == 0 or n == 1) {
//         return n;
//     }
//     dp[0] = 0;
//     dp[1] = 1;
//     for (int i = 2; i <= n; i++) {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];
// }
// Time complexity - O(n)
// Space complexity - O(n)

// method 2
int fib(int n) {
    int dp[100] = {0};
    if (n == 0 or n == 1) {
        return n;
    }
    int a = 0;
    int b = 1;
    int c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}
// Time complexity - O(n)
// Space complexity - O(1)

int main() {
    int n = 3;

    cout << fib(n);
}
