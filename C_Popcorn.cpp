#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
#define all(x) x.begin(),x.end()
int MOD=1e9+7;

int main() {
    ll n, m;
    cin >> n >> m;
    vector<string> S(n);
    rep(i,0,n)
    {
        cin >> S[i];
    }
    vector<bitset<10>> flavorSets(n);
    bitset<10> allFlavors;
    rep(j,0,m)
    {
        allFlavors.set(j);
    }
    rep(i,0,n) 
    {
        rep(j,0,m) 
        {
            if (S[i][j] == 'o')
                flavorSets[i].set(j);
        }
    }
    ll minm = n;
    rep(i,1,1<<n) 
    {
        bitset<10> coveredFlavors;
        ll countStands = 0;
        rep(j,0,n) 
        {
            if (i & (1 << j)) 
            {
                coveredFlavors |= flavorSets[j];
                countStands++;
            }
        }
        if (coveredFlavors == allFlavors)
        minm = min(minm, countStands);
    } 
    cout << minm << endl;
}
