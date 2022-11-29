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
        cin>>arr[i];
        ll t=0;
        rep(i,1,n-1)
        {
            if(arr[i]>arr[i-1]+arr[i+1])
            t++;
        }
        if(k==1)
        cout<<(n-1)/2<<"\n";
        else
        cout<<t<<endl;
    }
}