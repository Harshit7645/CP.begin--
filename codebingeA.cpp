#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i=a;i<b;i++)
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
        double x1,x2,x3,y1,y2,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        double d1,d2,d3,d4;
        d1=x1-x2;
        d2=y1-y2;
        d3=x1-x3;
        d4=y1-y3;
        if(sqrt(d1*d1+ d2*d2)<sqrt(d3*d3+d4*d4))
        cout<<"ICPC\n";
        else
        cout<<"Pronite\n";
    }
}