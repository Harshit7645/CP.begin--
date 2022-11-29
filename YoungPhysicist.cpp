#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,i,x,y,z;
    cin>>n;
    ll sum1=0,sum2=0,sum3=0;
    for(i=0;i<n;i++)
    {
        cin>>x>>y>>z;
        sum1+=x;
        sum2+=y;
        sum3+=z;
    }
    if(sum1==0 && sum2==0 && sum3==0)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}