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
    ll n;
    cin>>n;
    ll arr[n];
    rep(i,0,n)
    {
        cin>>arr[i];
    }
    ll s=0,ans=0;
    rep(i,0,n)
    {
        if(arr[i]>0)
        s+=arr[i];
        else if(arr[i]<0 && s>0)
        {
            s+=arr[i];
        }
        else
        {
            s=0;
            ans++;
        }
    }
    cout<<ans<<endl;
}