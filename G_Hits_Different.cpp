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
    ll arr[1500][1500]={};
    ll ans[1000005];
    ll curr=1;
    rep(i,1,1500)
    {
        repr(j,i-1,1)
        {
            arr[j][i-j]=arr[j-1][i-j]+arr[j][i-j-1]-arr[j-1][i-j-1]+curr*curr;
            ans[curr]=arr[j][i-j];
            curr++;
        }
    }
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n;
        cin>>n;
        cout<<ans[n]<<"\n";
    }
}   