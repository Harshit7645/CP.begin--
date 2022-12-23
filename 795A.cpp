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
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        ll ans1=0,ans2=0;
        rep(i,0,n)
        {
            if(arr[i]%2==0)
            {
                ans1++;
            }
            if(arr[i]%2==1)
            {
                ans2++;
            }
        }
        ll ans=min(ans1,ans2);
        cout<<ans<<endl;
    }
}