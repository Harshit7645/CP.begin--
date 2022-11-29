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
        ll n,ans=0;
        cin>>n;
        ll arr[n];
        rep(i,0,n)
        cin>>arr[i];
        ll min=1e9,ma=0,maxi=0,mini=0;
        rep(i,0,n)
        {
            if(arr[i]>ma)
            {
                ma=arr[i];
                maxi=i;
            }
            if(arr[i]<min)
            {
                min=arr[i];
                mini=i;
            }
        }
           for(int i=0;i<n;i++){
            if(i!=n-1)
            {
                ans=max(ans,arr[i]-arr[i+1]);
            }
        }
        ans=max(ans,arr[n-1]-arr[0]);
        ans=max(ans,arr[n-1]-min);
        ans=max(ans,ma-arr[0]);
        cout<<ans<<endl;
    }
}