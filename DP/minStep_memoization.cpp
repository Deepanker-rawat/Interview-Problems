#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

int minStep(int n, int dp[]) {
    // base case
    if (n == 1) {
        return 0;
    }
    // Check if n is already in the table
    if (dp[n] != 0) {
        return dp[n];
    }

    // Recursive case
    int ans1, ans2, ans3;
    ans1 = ans2 = ans3 = INT_MAX;

    if (n % 3 == 0) {
        ans1 = minStep(n / 3, dp) + 1;
    }
    if (n % 2 == 0) {
        ans2 = minStep(n / 2, dp) + 1;
    }
    ans3 = minStep(n - 1, dp) + 1;

    dp[n] = min(ans1, min(ans2, ans3));

    return dp[n];
}
// Time complexity - O(n)
// Space complexity - O(n)
int main() {
    int n = 30;
    int dp[100];
    memset(dp, 0, sizeof(dp));

    cout << minStep(n, dp);
}