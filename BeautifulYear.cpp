#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
int main()
{
    ll n,i,a,b,c,d;
    cin>>n;
    for(i=n+1;;i++)
    {
        a=i%10;
        b=(i/10)%10;
        c=(i/100)%10;
        d=(i/1000)%10;
        if(a!=b && b!=c && c!=d && d!=a && a!=c && b!=d)
        {
            cout<<i<<endl;
            break;
        }
    }
}