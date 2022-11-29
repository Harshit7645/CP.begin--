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
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        ll ans=0;
        rep(i,0,n)
        {
            if(arr[i%k]<arr[i])
            arr[i%k]=arr[i];
            if(i<k)
            continue;
            else
            arr[i]=0;
        }
        rep(i,0,k)
        {
            ans+=arr[i];
        }
        cout<<ans<<endl;
    }
}