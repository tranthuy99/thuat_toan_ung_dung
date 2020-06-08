#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

string s;
int dp[1001][1001];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    s="(??(??))";
    int n = s.size();
    s = "@"+s;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= n; j++){
            if (s[i] == '(' && j != 0) dp[i][j] = dp[i-1][j-1];
            else if (s[i] == ')') dp[i][j] = dp[i-1][j+1];
            else if (s[i] == '?') dp[i][j] = (dp[i-1][j+1] + (j != 0?dp[i-1][j-1]:0))%MOD;
        }
    }
    cout << dp[2][0];
    return 0;
}
