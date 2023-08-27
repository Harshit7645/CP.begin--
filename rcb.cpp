#include <iostream>
#include <vector>

using namespace std;

const int mod = 1000000007;

int main() {
    int n;
    cin >> n;
    
    vector<vector<long long>> dp(26, vector<long long>(n, 0));
    
    for (int j = 0; j < 26; j++) {
        dp[j][0] = 1;
    }
    
    for (int k = 1; k < n; k++) {
        long long tot = 0;
        for (int j = 0; j < 26; j++) {
            tot = (tot + dp[j][k - 1]) % mod;
        }
        for (int j = 0; j < 26; j++) {
            dp[j][k] = (dp[j][k] + tot) % mod;
        }
        if (n > 2) {
            dp[1][k] = (dp[1][k] - dp[17][k - 2] + mod) % mod;
        }
    }
    
    long long ans = 0;
    
    for (int j = 0; j < 26; j++) {
        ans = (ans + dp[j][n - 1]) % mod;
    }
    
    cout << ans << endl;
    
    return 0;
}
