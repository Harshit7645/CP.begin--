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
        ll a,b,n,i,l=0;
        cin>>a>>b>>n;
        if(a%b==0)
        cout<<-1<<"\n";
        else{
        if(n%a==0)
        l=n;
        else
        l=((n/a)+1)*a;
        for(i=l;;i+=a)
        {
            if(i%b!=0)
            {
                cout<<i<<"\n";
                break;
            }
        }
        }
    }
}