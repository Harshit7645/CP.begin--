#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll t;
    cin>>t;
    for(ll l=0;l<t;l++)
    {
        ll n,k,i;
        cin>>n>>k;
        if(n%2==0)
        cout<<(k-1)%n+1<<"\n";
        else
        {
            cout<<(k-1+((k-1)/(n/2)))%n+1<<"\n";
        }
    }
}