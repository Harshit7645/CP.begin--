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
        ll arr[n],b[n];
        rep(ii,0,n)
        {
            cin>>arr[ii];
        }
        rep(i,0,n)
        {
            b[i]=arr[n-i-1];
        }
        if(is_sorted(arr,arr+n))
        {
            cout<<"0\n";
            continue;
        }
        else if(is_sorted(b,b+n))
        {
            cout<<b[n-1]+1<<"\n";
            continue;
        }
        ll avg1=0,avg2=0,mx=0;
        rep(i,0,n-1)
        {
            if(arr[i]>arr[i+1])
            {
                //req[arr[i]]++;
                avg1=floor((double)(arr[i]+arr[i+1])/2);
                avg2=ceil((double)(arr[i]+arr[i+1])/2);
                if(avg1==avg2)
                mx=max(mx,avg1);
                else{
                    if(abs(arr[i]-avg1)<=abs(arr[i+1]-avg1))
                    mx=max(mx,avg1);
                    else if(abs(arr[i]-avg2)<=abs(arr[i+1]-avg2))
                    mx=max(mx,avg2);
                }
            }
        }
        rep(i,0,n)
        {
            arr[i]=abs(arr[i]-mx);
        }
        if(is_sorted(arr,arr+n))
        cout<<mx<<"\n";
        else
        cout<<"-1\n";
    }
}