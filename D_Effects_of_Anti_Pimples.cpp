#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=998244353;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    //cin>>tt;
    // vector<ll>primes;
    // rep(i,2,1e5)
    // {
    //     if(isPrime(i))
    //     primes.push_back(i);
    // }
    // rep(i,0,primes.size())
    // {
    //     cout<<primes[i]<<" ";
    // }
    //cout<<primes.size()<<"\n";
    while(tt--)
    {
        ll n;
        cin>>n;
        ll arr[n+1];
        rep(i,1,n+1)
        {
            cin>>arr[i];
        }
        ll maxmult[n+1];
        rep(i,1,n+1)
        {
            maxmult[i]=0;
            rep(j,i,n+1)
            {
                maxmult[i]=max(maxmult[i],arr[j]);
                j+=(i-1);
            }
        }
        sort(maxmult+1,maxmult+n+1);
        ll ans=0,curr=1;
        rep(i,1,n+1)
        {
            ans=(ans+(maxmult[i]*curr)%M)%M;
            curr=(curr*2)%M;
        }
        cout<<ans<<"\n";
    }
}   