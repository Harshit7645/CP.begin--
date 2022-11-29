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
        ll n,i,ans=0;
        cin>>n;
        ll arr[n],j;
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        cout<<ans<<endl;
        ll c=0;
        for(i=n-1;i>=1;i--)
        {
            if(arr[i-1]>arr[i])
            break;
            else
            c++;
        }
    }
}