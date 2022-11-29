#include<iostream>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll t;
    cin>>t;
    for(ll k=0;k<t;k++)
    {
        ll n,i;
        cin>>n;
        vector<ll> arr(n);
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());
        ll flag=0;
        if(arr[1]-arr[0]!=1)
        {
            flag=1;
            if(arr[2]-arr[1]==1)
            cout<<arr[0]<<"\n";
            else
            cout<<arr[1]<<"\n";
        }
        else{
        for(i=1;i<n-1;i++)
        {
            if(arr[i+1]!=arr[i]+1)
            {
                flag=1;
            }
            if(flag==1)
            break;
        }
        cout<<arr[i+1]<<"\n";}
    }
}
