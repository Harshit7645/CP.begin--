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
        //ll s=0;
        rep(i,0,n)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        ll b=0,red=0;
        ll l=1,r=n-1,F=0;
        b+=arr[0];
        while(l<r)
        {
            b+=arr[l];
            red+=arr[r];
            if(b<red)
            {
                F=1;
                break;
            }
            l++;
            r--;
        }
        if(F)
        PYES;
        else
        PNO;
    }
}