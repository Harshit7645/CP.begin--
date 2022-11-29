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
    ll n;
    cin>>n;
    ll arr[n];
    cin>>arr[0];
    ll max=arr[0],min=arr[0];
    ll ans=0;
    rep(i,1,n)
    {
        cin>>arr[i];
        if(arr[i]>max)
        {
            ans++;
            max=arr[i];
        }
        else if(arr[i]<min)
        {
            ans++;
            min=arr[i];
        }
    }
    cout<<ans<<endl;

}