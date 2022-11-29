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
        ll n;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        map<ll,ll>m;
        rep(i,0,n)
        {
            m[arr[i]]++;
        }
        ll max=0,temp=0;
        rep(i,0,n)
        {
            if(m[arr[i]]>max)
            {
                max=m[arr[i]];
                temp=i;
            }
        }
        ll flag=0,c=0;
        for(auto x:m)
        {
            if(x.second==max)
            c++;
            if(c>1)
            {
                flag=1;
                break;
            }
        }
        // for(auto x:m)
        // cout<<x.first<<" "<<x.second<<"\n";
        // cout<<c<<"\n";
        if(max>1 && flag==0)
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
}