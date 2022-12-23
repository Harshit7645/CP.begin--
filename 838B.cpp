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
        ll arr[n];
        vector<ll>power;
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        ll i=1;
        while (i<10e9)
        {
            power.push_back(i);
            i*=2;
        }
       // cout<<power.size()<<endl;
       vector<pair<ll,ll>>v;
       rep(i,0,n)
       {
            rep(j,0,power.size())
            {
                if(arr[i]==power[j])
                break;
                if(arr[i]<power[j])
                {
                    v.push_back({i+1,power[j]-arr[i]});
                    break;
                }
            } 
       }
       cout<<v.size()<<endl;
       for(auto x:v)
       {
            cout<<x.first<<" "<<x.second<<"\n";
       }
    }
}