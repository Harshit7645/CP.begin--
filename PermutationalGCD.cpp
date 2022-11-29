#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
int main()
{
    ll t;
    cin>>t;
    for(ll x=0;x<t;x++)
    {
        ll n,i;
        cin>>n;
        ll arr[n];
        for(i=0;i<n;i++)
        {
            arr[i]=i+1;
        }
        sort(arr,arr+n);
        ll temp;
        for(i=0;i<n;i+=3)
        {
            if(i<n && i+2<n)
            {
                temp=arr[i];
                arr[i]=arr[i+2];
                arr[i+2]=temp;
            }
        }
        for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
        cout<<"\n";
    }
}