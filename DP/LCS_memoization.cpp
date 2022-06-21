#include <bits/stdc++.h>
using namespace std;
 
int dp[1000][1000];
string getLCS(string &s1, string &s2, int len){
    string LCS;
    int i=0, j=0;

    while(len>0){
        if(s1[i]==s2[j]){
            LCS.push_back(s1[i]);
            i++;
            j++;
            len--;
        }
        else{
            if(dp[i][j+1] > dp[i+1][j])
                j++;
            else 
                i++;
        }
    }

    return LCS;
}
int lenLCS(int i, int j, int x, int y, string &s1, string &s2){
    if(i>=x or j>= y){
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i] == s2[j]){
            dp[i][j] =  1 + lenLCS(i+1, j+1, x, y, s1, s2); 
            return dp[i][j];
        }
        else
            dp[i][j] =  max(lenLCS(i+1, j, x, y, s1, s2), lenLCS(i, j+1, x, y, s1, s2));
            return dp[i][j];
}

string solve(string s1, string s2){
    memset(dp, -1, sizeof dp);
    int x = s1.length();
    int y = s2.length();
    int len = lenLCS(0,0,x,y,s1,s2);

    return getLCS(s1,s2,len);
} 
int main() {
        string s,t;
        cin>>s>>t;

        cout<<solve(s,t);

}