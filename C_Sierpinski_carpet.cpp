#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define all(x) x.begin(),x.end()
int M=1e9+7;
using namespace std;

// Function to generate the carpet of level n
vector<string> generate_carpet(ll n) {
    if (n == 0) {
        return vector<string>{"#"};
    }
    vector<string> prev_carpet = generate_carpet(n - 1);
    int size = prev_carpet.size();
    int new_size = size * 3;
    vector<string> new_carpet(new_size, string(new_size, ' '));
    rep(i,0,3) {
        rep(j,0,3) {
            rep(x,0,size) {
                rep(y,0,size) {
                    if (i == 1 && j == 1) {
                        new_carpet[i * size + x][j * size + y] = '.';
                    } else {
                        new_carpet[i * size + x][j * size + y] = prev_carpet[x][y];
                    }
                }
            }
        }
    }

    return new_carpet;
}

int main() {
    ll N;
    cin >> N;
    vector<string> carpet = generate_carpet(N);
    for (const string &line : carpet) {
        cout << line << endl;
    }
    return 0;
}
