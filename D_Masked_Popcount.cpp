#include <iostream>
#include <cstdint>
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;i++)
using namespace std;

const int MOD = 998244353;

// Function to compute the sum of popcount(k & M) for k from 0 to N, modulo MOD
uint64_t sum_popcount(uint64_t N, uint64_t M) {
    uint64_t result = 0;
    
    // Iterate over each bit position (0 to 59 because 2^60 - 1 has 60 bits)
    rep(i,0,60) {
        uint64_t bit_mask = 1ULL << i;
        
        if (M & bit_mask) {
            uint64_t full_cycles = (N + 1) / (bit_mask << 1);
            uint64_t remainder = (N + 1) % (bit_mask << 1);
            uint64_t count_ones = full_cycles * bit_mask + max(remainder, bit_mask) - bit_mask;
            result = (result + count_ones) % MOD;
        }
    }
    
    return result;
}

int main() {
    uint64_t N, M;
    cin >> N >> M;
    
    uint64_t result = sum_popcount(N, M);
    cout << result << endl;
    
    return 0;
}
