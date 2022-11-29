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
        ll n,odd=0;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        vector<ll>even;
        rep(i,0,n)
        {
            if(arr[i]%2==0)
            even.push_back(arr[i]);
            else
            odd++;
        }
        ll small=1e9;
        if(odd)
        {
            cout<<even.size()<<"\n";
            continue;
        }
        rep(i,0,even.size())
        {
            ll temp=0;
            while(even[i]%2==0)
            {   
                temp++;
                even[i]/=2;
            }
            small=min(small,temp);
        }
        cout<<small+even.size()-1<<endl;
    }
}