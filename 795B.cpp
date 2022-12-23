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
        ll arr[n];
        map<ll,ll>m;
        rep(i,0,n)
        {
            cin>>arr[i];
            m[arr[i]]++;
        }
        ll f=0;
        for(auto x:m)
        {
            if(x.second==1)
            {
                f=1;
                break;
            }
        }
        if(f)
        cout<<-1<<endl;
        else
        {
            map<ll,vector<ll>>mp;
            rep(i,0,n)
            {
                mp[arr[i]].push_back(i+1);
            }
            for(auto x:mp)
            {
                //cout<<x.second[x.second.size()-1]<<" ";
                rep(i,1,x.second.size()+1)
                {
                    cout<<x.second[i%x.second.size()]<<" ";
                }
                //cout<<endl;
            }
            cout<<endl;
        }
    }
}