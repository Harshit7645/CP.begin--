#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int N;
    std::cin >> N;

    std::vector<int> dp(N + 1, 0);

    for (int i = 2; i <= N; ++i) {
        int prefix_sum = 0;
        for (int j = 1; j < i; ++j) {
            dp[i] = (1LL * (1 + dp[j]) * (j - i) % MOD + 1LL * dp[j] * prefix_sum % MOD) % MOD;
            prefix_sum = (prefix_sum + dp[j]) % MOD;
        }
    }

    int mod_inv = 1;
    for (int i = 2; i <= N; ++i) {
        mod_inv = 1LL * mod_inv * (MOD - MOD / i) % MOD;
    }

    for (int i = 1; i <= N; ++i) {
        int result = 1LL * dp[i] * mod_inv % MOD;
        std::cout << result << " ";
    }
    std::cout << std::endl;

    return 0;
}
