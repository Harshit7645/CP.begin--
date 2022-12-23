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
        ll arr[n],sum=0;
        rep(i,0,n)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        ll f=0;
        rep(i,0,n)
        {
            double am=(double)(sum-arr[i])/(double)(n-1);
            // cout<<am<<"  ";
            if(am==arr[i])
            {
                f=1;
                break;
            }
        }
        if(f)
        PYES;
        else
        PNO;

    }
}