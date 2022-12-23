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
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        sort(arr+1,arr+n);
        ll c=arr[0];
        ll i=0;
        while(arr[i]<c)
        {
            i++;
        }
        c=i+1;
        rep(i,c,n)
        {
            if(arr[i]>arr[0])
            {
                arr[0]+=ceil((double)(arr[i]-arr[0])/2);
            }
            if(arr[i]<arr[0])
            {
                continue;
            }
        }
        cout<<arr[0]<<endl;
    }
}