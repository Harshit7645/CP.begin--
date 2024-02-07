#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int M=1e9+7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll g=0;
        if(arr[0]==arr[n-1])
        {
            cout<<"0\n";
            continue;
        }
        if(arr[0]<=k && arr[n-1]>=k)
        {
            cout<<"-1\n";
            continue;
        }
        else if(arr[0]>k)
        {
            rep(i,0,n)
            {
                arr[i]-=k;
                g=gcd(g,arr[i]);
            }
        } 
        else {
            rep(i,0,n)
            {
                arr[i]=k-arr[i];
                g=gcd(g,arr[i]);
            }
        }
        ll ans=0;
        rep(i,0,n)
        {
            ans+=arr[i]/g-1;
            //cout<<ans<<" ";
        }
        cout<<ans<<"\n";
    }
}   