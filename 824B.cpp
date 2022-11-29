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
        ll n;
        cin>>n;
        ll arr[n],mx=0;
        //vector<ll>half;
        rep(i,0,n)
        {
            cin>>arr[i];
            mx=max(mx,arr[i]);
        }
        sort(arr,arr+n);
        if(n==1)
        {
            cout<<"0\n";
            continue;
        }
        else
        {
            ll ans=0;
            rep(i,1,n)
            {
                if(arr[i]>2*arr[0]-1)
                {
                    ans+=ceil((1.0*arr[i]/(2*arr[0]-1)*1.0))-1;
                }
            }
            cout<<ans<<"\n";
        }
    }
}