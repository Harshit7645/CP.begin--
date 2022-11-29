#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll a vector<ll>a 
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n],i,j,p=0,maxi=2*(n-1);
        vector<ll>sq;
        //map<ll,ll>m;
        for(i=0;i*i<=maxi;i++)
        {
            sq.push_back(i*i);
        }
        set<int>s;  
        ll ans[n],ptr=sq.size()-1;
        for(i=n-1;i>=0;i--)
        {
            ll other=sq[ptr]-i;
            while(other>=n || s.find(other)!=s.end())
            {
                ptr--;
                other=sq[ptr]-i;
            }
            ans[other]=i;
            //sq[ptr]=other-i;
            s.insert(other);
        }
        rep(i,0,n)
        cout<<ans[i]<<" ";
        cout<<endl;
        
    }
}
