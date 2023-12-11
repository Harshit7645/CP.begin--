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

ll MEX(ll art[],ll n)
{
    sort(art,art+n);
    ll c=0;
    rep(i,0,n)
    {
        if(c!=art[i])
        break;
        else
        c++;
    }
    return c;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll tt=1;
    cin>>tt;
    while(tt--)
    {
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        rep(j,0,k)
        {
            rep(i,0,n)
            {
                arr[i]=MEX(arr,n);
            }
        }
        //cout<<MEX(arr,n)<<endl;     
        rep(i,0,n)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}   