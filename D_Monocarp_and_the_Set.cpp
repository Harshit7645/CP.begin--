#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
ll M=998244353;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    //cin>>tt;
    while(tt--)
    {
        ll n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<ll> inv(n + 1, 1);
        rep(i,2,n+1){
            inv[i] =M - 1ll * M / i * inv[M % i] % M;
        }
        ll prod=1;
        rep(i,1,n-1)
        {
            if(s[i]=='?')
            prod=prod*i%M;
            //cout<<og[i]<<" ";
        }
        if(s[0]=='?')
        cout<<"0\n";
        else
        cout<<prod<<"\n";
        while(m--)
        {
            ll pos;
            char ch;
            cin>>pos>>ch;
            pos--;
            if(pos && s[pos]=='?')
            prod=prod*inv[pos]%M;
            s[pos]=ch;
            if(pos && s[pos]=='?')
            prod=prod*pos%M;
            if(s[0]!='?')
            cout<<prod<<"\n";
            else
            cout<<"0\n";
        }
    }
}   