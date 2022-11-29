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
        ll n,i;
        cin>>n;
        ll arr[n],min;
        rep(i,0,n)
        {
            cin>>arr[i];

        }
        sort(arr,arr+n);
        min=arr[0];
        ll ans=0;
        rep(i,0,n)
        {
            ans=gcd(ans,arr[i]-min);
        }
        if(!ans)
        cout<<"-1"<<"\n";
        else
        cout<<ans<<endl;
    }
}