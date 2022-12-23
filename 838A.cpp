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
        vector<ll>odd,even;
        rep(i,0,n)
        {
            cin>>arr[i];
            if(arr[i]%2)
            odd.push_back(arr[i]);
            else
            even.push_back(arr[i]);
        }
        ll mini=10e7,c=0;
        for(auto x:odd)
        {
            ll t=x;
            while(t%2==1)
            {
                t/=2;
                c++;
            }
            mini=min(mini,c);
            c=0;
        }
        c=0;
        ll mi=10e7;
        for(auto x:even)
        {
            ll t=x;
            while(t%2==0)
            {
                t/=2;
                c++;
            }
            mi=min(mi,c);
            c=0;
        }
        if(odd.size()%2==0)
        cout<<0<<endl;
        else
        cout<<min(mini,mi)<<endl;
    }
}