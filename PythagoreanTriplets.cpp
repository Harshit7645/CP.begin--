#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    for(ll x=0;x<t;x++)
    {
        ll n,l;
        cin>>n;
        l=sqrt(2*n-1);
        cout<<(l-1)/2<<endl;
    }
}