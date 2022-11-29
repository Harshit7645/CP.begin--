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
        ll n,c,i;
        cin>>n>>c;
        ll arr[n],sum=0;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(sum<=c)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
}