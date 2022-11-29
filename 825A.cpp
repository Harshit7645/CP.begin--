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
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>v1(n),v2(n);
        ll c1=0,c2=0,ans=0;
        rep(i,0,n)
        {
            cin>>v1[i];
        }
        rep(i,0,n)
        {
            cin>>v2[i];
        }
        rep(i,0,n)
        {
            if(v1[i]!=v2[i])
            c1++;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        rep(i,0,n)
        {
            if(v1[i]!=v2[i])
            c2++;
        }
        c2++;
        cout<<min(c1,c2)<<endl;
    }
}