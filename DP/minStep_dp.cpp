#include <climits>
#include <cstring>
#include <iostream>
using namespace std;

int minStep(int N) {
    // base case
    int dp[N + 1];

    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= N; i++) {
        if (i % 2 == 0 and i % 3 == 0) {
            dp[i] = min(dp[i / 2], min(dp[i / 3], dp[i - 1]));
        } else if (i % 3 == 0) {
            dp[i] = min(dp[i / 3], dp[i - 1]);
        } else if (i % 2 == 0) {
            dp[i] = min(dp[i / 2], dp[i - 1]);
        } else {
            dp[i] = dp[i - 1];
        }
        dp[i] += 1;
    }

    return dp[N];
}
// Time complexity - O(n)
// Space complexity - O(n)
int main() {
    int n = 30;

    cout << minStep(n);
}