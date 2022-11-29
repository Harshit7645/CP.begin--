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
        ll n,m,i,j,a,b,max,ans1,ans2;
        cin>>n>>m;
        max=0;
        for(i=n;i<=m;i++)
        {
            a=i;
            b=m-(m%i);
            if(abs(a-b)>=max)
            {
                ans1=a;
                ans2=b;
                max=abs(ans1-ans2);
            }
        }
        cout<<ans1<<" "<<ans2<<"\n";
    }
}