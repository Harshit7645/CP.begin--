#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        ll one=0,ones=0;
        rep(i,0,n)
        {
            if(a[i]=='1')
            one++;
            if(b[i]=='1')
            ones++;
        }
        if(one==ones)
        PYES;
        else
        PNO;
    }
}