#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

// Function to compute the number of valid strings
int count_valid_strings(int K, const vector<int>& C) {
    vector<long long> dp(K + 1, 0);
    dp[0] = 1;  // Base case: 1 way to make an empty string

    // Iterate through each character's constraint
    for (int i = 0; i < 26; ++i) {
        int max_count = C[i];
        vector<long long> new_dp(K + 1, 0);
        
        for (int used_length = 0; used_length <= K; ++used_length) {
            // Apply the character count constraints
            for (int count = 0; count <= max_count && used_length + count <= K; ++count) {
                new_dp[used_length + count] = (new_dp[used_length + count] + dp[used_length]) % MOD;
            }
        }
        dp = new_dp;  // Move to the next character
    }

    // Sum up the valid counts for lengths from 1 to K
    long long result = 0;
    for (int length = 1; length <= K; ++length) {
        result = (result + dp[length]) % MOD;
    }
    return result;
}

int main() {
    int K;
    cin >> K;
    vector<int> C(26);
    for (int i = 0; i < 26; ++i) {
        cin >> C[i];
    }
    cout << count_valid_strings(K, C) << endl;
    return 0;
}
