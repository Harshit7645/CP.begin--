#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"No\n"
#define PYES cout<<"Yes\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,k;
        cin>>n>>k;
        vector<ll> s(k);
        rep(i,0,k)
        {
            cin>>s[i];
        }
        //ll f=0;
        if(k==1)
        {
            PYES;
            continue;
        }
        vector<ll>req(k-1),req1(k-1);
        rep(i,0,k-1)
        {
            ll temp=s[i+1]-s[i];
            req[i]=temp;
            req1[i]=temp;
        }
        sort(req1.begin(),req1.end());
        // for(auto x:req)
        // {
        //     cout<<x<<" ";
        // }
        if(req!=req1)
        {
            PNO;
            continue;
        }
        if((n-k+1)*req[0]>=s[0])
        {
            PYES;
            continue;
        }
        else
        {
            PNO;
            continue;
        }
        // req.erase();
        // req1.erase();
    }
}