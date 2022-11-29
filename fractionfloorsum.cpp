#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n/2;i++)
    ans+=n/i;
    ans+=(n-(n/2));
    cout<<ans<<"\n";
} 