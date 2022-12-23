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
        ll a[n],maxi=0;
        rep(i,0,n)
        {
            cin>>a[i];
            maxi=max(maxi,a[i]);
        }
        ll m;
        cin>>m;
        ll b[m],mx=0;
        rep(i,0,m)
        {
            cin>>b[i];
            mx=max(mx,b[i]);
        }
        if(maxi==mx)
        {
            cout<<"Alice\n";
            cout<<"Bob\n";
        }
        else
        {
            if(maxi>mx){
            cout<<"Alice\n";
            cout<<"Alice\n";
            }
            else{
            cout<<"Bob\n";
            cout<<"Bob\n";
            }
        }
    }
}