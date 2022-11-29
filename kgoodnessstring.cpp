#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    rep(mn,1,t+1)
    {
        ll n,k,x;
        cin>>n>>k;
        string s;
        cin>>s;
        ll ans=0;
        rep(i,0,n/2)
        {
            if(s[i]!=s[n-i-1])
            ans++;
        }
        cout<<"Case #"<<mn<<": "<<abs(k-ans)<<endl;
    }
}