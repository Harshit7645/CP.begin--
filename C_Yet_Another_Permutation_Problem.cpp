#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

vector<ll> sieve_of_eratosthenes(int n)
{
    bool is_prime[n + 1];
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    vector<ll>ans;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    vector<ll>primes=sieve_of_eratosthenes(1e5);
    // rep(i,0,primes.size())
    // cout<<primes[i]<<" ";
    //cout<<primes.size()<<"\n";
    while(tt--)
    {
        ll n;
        cin>>n;
        rep(i,1,n+1)
        {
            for(int j=i;j<=n;j*=2)
            {
                cout<<j<<" ";
            }
            i++;
        }
        cout<<"\n";
    }
}   