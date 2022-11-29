#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    for(ll k=0;k<t;k++)
    {
        ll n,i,avg,sum=0,max=0,min=1e9,temp=0;
        cin>>n;
        ll arr[n];
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum%n)
        cout<<1<<"\n";
        else
        cout<<"0\n";
    }

}