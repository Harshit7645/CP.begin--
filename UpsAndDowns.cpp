
#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    for( ll k=0;k<t;k++)
    {
        ll n,i;
        cin>>n;
        ll arr[n];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr,arr+n);
        if(n<3)
        {
            for(i=0;i<n;i++)
            cout<<arr[i]<<" ";
            cout<<"\n";
        }
        else{
        for(i=0;i<n;i+=3)
        {
            ll temp=arr[i+2];
            arr[i+2]=arr[i+1];
            arr[i+1]=temp;
        }
        for(i=0;i<n;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        }

    }
}