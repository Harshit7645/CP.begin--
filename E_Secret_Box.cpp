#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define all(x) x.begin(),x.end()
ll M=1e9+7;
using namespace std;

ll max_locations_in_box(ll x, ll y, ll z, long long k) {
    ll max_positions = 0;
    // Loop over possible values for a
    rep(a,1,x+1) {
        if (k % a == 0) {
            long long k_div_a = k / a;
            // Loop over possible values for b
            rep(b,1,y+1) {
                if (k_div_a % b == 0) {
                    ll c = k_div_a / b;
                    if (c <= z) {
                        max_positions = max(max_positions, (x - a + 1) * (y - b + 1) * (z - c + 1));
                    }
                }
            }
        }
    }
    return max_positions;
}

int main() {
    ll t;
    cin >> t;
    while(t--){
        ll x, y, z, k, results;
        cin >> x >> y >> z >> k;
        results = max_locations_in_box(x, y, z, k);
        cout << results << endl;
    }
}
