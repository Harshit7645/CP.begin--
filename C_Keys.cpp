    #include <iostream>
    #include <vector>
    typedef long long ll;
    using namespace std;

    ll count_valid_combinations(int N, int M, int K, const vector<vector<ll>>& tests, const vector<char>& results) {
        int valid_count = 0;

        // Iterate over all possible combinations of real/dummy keys
        for (int mask = 0; mask < (1 << N); ++mask) {
            bool valid = true;

            // Check each test
            for (int i = 0; i < M; ++i) {
                int real_count = 0;
                const vector<ll>& keys = tests[i];

                // Count the number of real keys in the current test
                for (int key : keys) {
                    if (mask & (1 << (key - 1))) {
                        ++real_count;
                    }
                }

                if (results[i] == 'o' && real_count < K) {
                    valid = false;
                    break;
                }
                if (results[i] == 'x' && real_count >= K) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ++valid_count;
            }
        }

        return valid_count;
    }

    int main() {
        ll N, M, K;
        cin >> N >> M >> K;

        vector<vector<ll>> tests(M);
        vector<char> results(M);

        for (int i = 0; i < M; ++i) {
            int Ci;
            cin >> Ci;
            tests[i].resize(Ci);

            for (int j = 0; j < Ci; ++j) {
                cin >> tests[i][j];
            }

            cin >> results[i];
        }

        ll result = count_valid_combinations(N, M, K, tests, results);
        cout << result << endl;

        return 0;
    }
