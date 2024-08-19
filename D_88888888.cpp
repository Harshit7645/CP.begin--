#include <iostream>
#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define all(x) x.begin(),x.end()
uint64_t M=998244353;
using namespace std;

uint64_t mod_power(uint64_t x, uint64_t y) {
    uint64_t res = 1;
    x=x%M; 
    assert(y>=0);
    while (y>0) {
        if (y%2)
            res=(res * x)%M;
        y=y/2; 
        x=(x*x)%M;
    }
    return res % M;
}

int main() {
    uint64_t N;
    cin >> N;
    string str = to_string(N);
    uint64_t L;
    L = (uint64_t)str.length();
    uint64_t result=(mod_power(10,N%(M-1)*L)-1)*mod_power(mod_power(10,L)-1,M-2)%M;
    result=N%M*result%M;
    cout<<result%M;
}
