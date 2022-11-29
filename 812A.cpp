#include<iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(i=a;i<b;i++)
#define PNO cout<<"NO\n"
#define PYES cout<<"YES\n"
#define vll x vector<ll>x;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,i;
        cin>>n;
        vector<ll>x1,x2,y1,y2;
        rep(i,0,n)
        {
            ll r,s;
            cin>>r>>s;
            if(r==0 && s>=0)
            y1.push_back(s);
            if(r==0 && s<0)
            y2.push_back(s);
            else if(s==0 && r>=0)
            x1.push_back(r);
            else if(s==0 && r<0)
            x2.push_back(r);
        }
        ll ans=0,max=0;
        for(i=0;i<x1.size();i++)
        {
            if(max<x1[i])
            max=x1[i];
        }
        ans+=2*abs(max);
        max=0;
        for(i=0;i<y1.size();i++)
        {
            if(max<y1[i])
            max=y1[i];
        }
        ans+=2*abs(max);
        max=0;
        for(i=0;i<x2.size();i++)
        {
            if(max>x2[i])
            max=x2[i];
        }
        ans+=2*abs(max);
        max=0;
        for(i=0;i<y2.size();i++)
        {
            if(max>y2[i])
            max=y2[i];
        }
        ans+=2*abs(max);
        cout<<ans<<endl;
    }
}