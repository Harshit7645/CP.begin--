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
    vector<ll>req;
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= n; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                is_prime[i] = false;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            req.push_back(i);
        }
    }
    return req;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    //vector<ll>req=sieve_of_eratosthenes(1e5);
    //cout<<req.size();
    while(tt--)
    {
        ll n;
        cin>>n;
        ll a[n];
        map<ll,ll>m;
        rep(i,0,n)
        {
            cin>>a[i];
            if(a[i]<=n)
            m[a[i]]++;
        }
        vector<ll>cnt(n+1,0);
        rep(i,1,n+1)
        {
            if(m[i]==0)
            continue;
            rep(j,i,n+1)
            {
                cnt[j]+=m[i];
                j+=(i-1);
            }
        }
        ll ans=0;
        rep(i,0,cnt.size())
        {
            ans=max(ans,cnt[i]);
        }
        cout<<ans<<"\n";
    }

}   