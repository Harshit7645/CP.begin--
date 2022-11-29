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
        ll n,ans=0;
        cin>>n;
        ll arr[n];
        vector<ll>req;
        //map<ll,ll>m;
        ll c=0;
        rep(i,0,n)
        {
            cin>>arr[i];
            if(arr[i]>=i+1)
            c++;
            else
            {
                req.push_back(c);
                c=0;
            }
        }
        if(c!=0)
        req.push_back(c);
        for(auto x:req)
        {
            ans+=x*(x+1)/2;
        }
        cout<<ans<<endl;
    }   
}