#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b;i>=a;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
typedef vector<ll> vll;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string a,b;
    cin>>a>>b;
    ll n1=a.length(),n2=b.length();
    if(n1==1 && a==b)
    {
        PYES;
        return 0;
    }
    else if(n1==1)
    {
        PNO; 
    return 0;
    }
    if(n1!=n2)
    {
        PNO;
        return 0;
    }
    else
    {
        ll c=0,c1=0;
        rep(i,0,n1)
        {
            if(a[i]=='1')
            c=1;
            if(b[i]=='1')
            c1=1;
        }
        if(c!=c1)
        {
            PNO;
        return 0;
        }
        else
        {
            PYES;
            return 0;
        }
        
    }
}