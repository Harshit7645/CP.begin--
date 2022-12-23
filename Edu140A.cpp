#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll vector<ll>;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        map<ll,ll>x,y;
        x[x1]++;
        x[x2]++;
        x[x3]++;
        y[y1]++;
        y[y2]++;
        y[y3]++;
        if(x.size()<=2 && y.size()<=2)
        PNO;
        else
        PYES;
        
    }
}