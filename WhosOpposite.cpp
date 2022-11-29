#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll maxi(ll,ll,ll);
int main()
{
    ll t;
    cin>>t;
    for(ll l=0;l<t;l++)
    {
        ll a,b,c,n,i;
        cin>>a>>b>>c;
        n=abs((a-b)*2);
        if(n>=maxi(a,b,c))
        {
            cout<<((c-1)+(n/2))%n+1<<endl;
        }
        else
        cout<<"-1\n";
    }
}
ll maxi(ll a,ll b,ll c)
{
    if(a>b)
    {
        if(a>c)
        return a;
        else
        return c;
    }
    else
    {
        if(b>c)
        return b;
        else
        return c;
    }
}