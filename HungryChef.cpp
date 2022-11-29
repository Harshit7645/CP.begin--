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
        ll x,y,n,r,i,temp,ans=0;
        cin>>x>>y>>n>>r;
        temp=0;
        if(r>=x*n)
        {        
            if(n*y<=r)
            ans=n;
            else   
            ans=((r-n*x)/(y-x));
            cout<<n-ans<<" "<<ans<<"\n";
        }
        else
        cout<<"-1 \n";
    }
}