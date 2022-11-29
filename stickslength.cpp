#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll n,i,sum=0,avg=0;
    cin>>n;
    int arr[n];
    for( i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    ll ans=0;
    for(i=0;i<n;i++)
    {
        ans+=abs(arr[n/2]-arr[i]);
    }
    cout<<ans<<"\n";
}