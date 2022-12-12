#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;

bool cancut(ll n)
{

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n,k;
    cin>>n>>k;
    ll arr[n],mx=0;
    rep(i,0,n)
    {
        cin>>arr[i];
        mx=max(mx,arr[i]);
    }
    mx=max(mx,k);
    ll l=1,r=k;
    while(l<r-1)
    {

    }
}