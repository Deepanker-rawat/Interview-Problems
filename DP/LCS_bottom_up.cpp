#include <bits/stdc++.h>
using namespace std;
 
int dp[1000][1000];

string LCS(int n, int m, string &s1, string &s2){
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (s1[i - 1] == s2[j - 1]) 
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else 
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);

	int i = n, j = m;
	string lcs = ""; 
	while (i > 0 && j > 0) {
		if (s1[i - 1] == s2[j - 1]) {
			lcs += s1[i - 1]; 
			i--, j--;
		}
		else {
			if (dp[i][j - 1] > dp[i - 1][j])
				j--; 
			else
				i--;
		}
	}
	reverse(lcs.begin(), lcs.end()); 

    return lcs;
}

int main() {
        string s1,s2;
        cin>>s1>>s2;
        memset(dp, 0, sizeof dp);
        int x = s1.length();
        int y = s2.length();

        cout<<LCS(x,y,s1,s2);

}