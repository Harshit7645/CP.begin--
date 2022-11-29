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
        ll n;
        cin>>n;
        ll a[n],i;
        rep(i,0,n)
        {
            cin>>a[i];
        }
        // vector<ll>b;
        // vector<ll>c;
        //b.push_back(a[n-1]);
        for(i=n-1;i>=1;i-=2)
        {
            if(a[i]<a[i-1])
            swap(a[i],a[i-1]);
        }
        ll flag=0;
        for(i=0;i<n-1;i++)
        {
            if(a[i+1]<a[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        cout<<"NO\n";
        else
        cout<<"YES\n";
    }
}